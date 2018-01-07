#include <CgnsInterface/CgnsFile2D.hpp>

CgnsFile2D::CgnsFile2D(const Grid& grid, const std::string& folderPath) : 
	CgnsFile(grid, folderPath) {
	this->coordinateIndices.resize(3);
	this->sectionIndices.resize(5);
	this->boundaryIndices.resize(4);
	this->numberOfNodes    = this->grid.coordinates.size();
	this->numberOfElements = this->grid.quadrilateralConnectivity.size();
	this->cellDimension    = this->grid.dimension;
	std::string folderName = this->folderPath + std::string("/") + std::to_string(numberOfNodes) + std::string("n_") + std::to_string(numberOfElements) + "e/"; createDirectory(folderName);
	this->fileName = folderName + std::string("Grid.cgns");

	if (cg_open(this->fileName.c_str(), CG_MODE_WRITE, &this->fileIndex)) cg_error_exit();
}

void CgnsFile2D::writeBase() {
	if (cg_base_write(this->fileIndex, this->baseName.c_str(), this->cellDimension, this->physicalDimension, &this->baseIndex)) cg_error_exit();
}

void CgnsFile2D::writeZone() {
	this->zoneSizes[0] = this->numberOfNodes;
	this->zoneSizes[1] = this->numberOfElements;
	this->zoneSizes[2] = 0;	
	if (cg_zone_write(this->fileIndex, this->baseIndex, this->zoneName.c_str(), &this->zoneSizes[0], Unstructured, &this->zoneIndex)) cg_error_exit();
}

void CgnsFile2D::writeCoordinates() {
	double coordinatesX[this->numberOfNodes];
	double coordinatesY[this->numberOfNodes];
	double coordinatesZ[this->numberOfNodes];
	for (cgsize_t i = 0; i < this->numberOfNodes; i++) {
		coordinatesX[i] = this->grid.coordinates[i][0];
		coordinatesY[i] = this->grid.coordinates[i][1];
		coordinatesZ[i] = 0.0; 
	}
	if (cg_coord_write(this->fileIndex, this->baseIndex, this->zoneIndex, RealDouble, "CoordinateX", coordinatesX, &this->coordinateIndices[0])) cg_error_exit();
	if (cg_coord_write(this->fileIndex, this->baseIndex, this->zoneIndex, RealDouble, "CoordinateY", coordinatesY, &this->coordinateIndices[1])) cg_error_exit();
	if (cg_coord_write(this->fileIndex, this->baseIndex, this->zoneIndex, RealDouble, "CoordinateZ", coordinatesZ, &this->coordinateIndices[2])) cg_error_exit();
}

void CgnsFile2D::writeSections() {
	cgsize_t* connectivities = determine_array_1d(grid.quadrilateralConnectivity);
	cgsize_t elementStart = 1;
	cgsize_t elementEnd = numberOfElements;
	if (cg_section_write(this->fileIndex, this->baseIndex, this->zoneIndex, "Quadrilateral", QUAD_4, elementStart, elementEnd, zoneSizes[2], connectivities, &sectionIndices[0])) cg_error_exit();
	delete connectivities;

	for (int i = 0; i < grid.boundaries.size(); i++) {
		elementStart = elementEnd + 1;
		elementEnd = elementStart + grid.boundaries[i].lineConnectivity.size() - 1;
		connectivities = determine_array_1d(grid.boundaries[i].lineConnectivity);
		if (cg_section_write(this->fileIndex, this->baseIndex, this->zoneIndex, this->grid.boundaries[i].name.c_str(), BAR_2, elementStart, elementEnd, this->zoneSizes[2], connectivities, &this->sectionIndices[i+1])) cg_error_exit();
		delete connectivities;
	}
}

void CgnsFile2D::writeBoundaryConditions() {
	for (int i = 0; i < grid.boundaries.size(); i++) {
		cgsize_t* indices = determine_array_1d(grid.boundaries[i].nodeIndices); 
		if (cg_boco_write(this->fileIndex, this->baseIndex, this->zoneIndex, this->grid.boundaries[i].name.c_str(), BCWall, PointList, this->grid.boundaries[i].nodeIndices.size(), indices, &this->boundaryIndices[i])) cg_error_exit();
		delete indices;
	}
}

CgnsFile2D::~CgnsFile2D() {
	if (cg_close(this->fileIndex)) cg_error_exit();
}
