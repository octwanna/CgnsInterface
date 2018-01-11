#include <CgnsInterface/CgnsFile3D.hpp>

CgnsFile3D::CgnsFile3D(const Grid& grid, const std::string& folderPath) : 
	CgnsFile(grid, folderPath) {
	this->coordinateIndices.resize(3);
	this->sectionIndices.resize(7);
	this->boundaryIndices.resize(6);
	this->numberOfNodes    = this->grid.coordinates.size();
	this->numberOfElements = this->grid.hexahedronConnectivity.size();
	this->cellDimension    = this->grid.dimension;
	std::string folderName = this->folderPath + std::string("/") + std::to_string(numberOfNodes) + std::string("n_") + std::to_string(numberOfElements) + "e/"; createDirectory(folderName);
	this->fileName = folderName + std::string("Grid.cgns");

	cg_open(this->fileName.c_str(), CG_MODE_WRITE, &this->fileIndex);
}

void CgnsFile3D::writeBase() {
	cg_base_write(this->fileIndex, this->baseName.c_str(), this->cellDimension, this->physicalDimension, &this->baseIndex);
}

void CgnsFile3D::writeZone() {
	this->zoneSizes[0] = this->numberOfNodes;
	this->zoneSizes[1] = this->numberOfElements;
	this->zoneSizes[2] = 0;	
	cg_zone_write(this->fileIndex, this->baseIndex, this->zoneName.c_str(), &this->zoneSizes[0], Unstructured, &this->zoneIndex);
}

void CgnsFile3D::writeCoordinates() {
	double coordinatesX[this->numberOfNodes];
	double coordinatesY[this->numberOfNodes];
	double coordinatesZ[this->numberOfNodes];
	for (cgsize_t i = 0; i < this->numberOfNodes; i++) {
		coordinatesX[i] = this->grid.coordinates[i][0];
		coordinatesY[i] = this->grid.coordinates[i][1];
		coordinatesZ[i] = this->grid.coordinates[i][2]; 
	}
	cg_coord_write(this->fileIndex, this->baseIndex, this->zoneIndex, RealDouble, "CoordinateX", coordinatesX, &this->coordinateIndices[0]);
	cg_coord_write(this->fileIndex, this->baseIndex, this->zoneIndex, RealDouble, "CoordinateY", coordinatesY, &this->coordinateIndices[1]);
	cg_coord_write(this->fileIndex, this->baseIndex, this->zoneIndex, RealDouble, "CoordinateZ", coordinatesZ, &this->coordinateIndices[2]);
}

void CgnsFile3D::writeSections() {
	cgsize_t* connectivities = determine_array_1d(grid.hexahedronConnectivity);
	cgsize_t elementStart = 1;
	cgsize_t elementEnd = numberOfElements;
	cg_section_write(this->fileIndex, this->baseIndex, this->zoneIndex, "Hexahedron", HEXA_8, elementStart, elementEnd, zoneSizes[2], connectivities, &sectionIndices[0]);
	delete connectivities;

	for (int i = 0; i < grid.boundaries.size(); i++) {
		elementStart = elementEnd + 1;
		elementEnd = elementStart + grid.boundaries[i].quadrilateralConnectivity.size() - 1;
		connectivities = determine_array_1d(grid.boundaries[i].quadrilateralConnectivity);
		cg_section_write(this->fileIndex, this->baseIndex, this->zoneIndex, this->grid.boundaries[i].name.c_str(), QUAD_4, elementStart, elementEnd, this->zoneSizes[2], connectivities, &this->sectionIndices[i+1]);
		delete connectivities;
	}
}

void CgnsFile3D::writeBoundaryConditions() {
	for (int i = 0; i < grid.boundaries.size(); i++) {
		cgsize_t* indices = determine_array_1d(grid.boundaries[i].nodeIndices); 
		cg_boco_write(this->fileIndex, this->baseIndex, this->zoneIndex, this->grid.boundaries[i].name.c_str(), BCWall, PointList, this->grid.boundaries[i].nodeIndices.size(), indices, &this->boundaryIndices[i]);
		delete indices;
	}
}

CgnsFile3D::~CgnsFile3D() {
	std::cout << "CGNS file output location: " << this->fileName << std::endl;
	cg_close(this->fileIndex);
}
