#include <CgnsInterface/CgnsFile.hpp>

CgnsFile::CgnsFile(const Grid& grid, const std::string& folderPath) : grid(grid), folderPath(folderPath), baseName("Base"), zoneName("Zone"), physicalDimension(3) {
	this->zoneSizes.resize(3);
}

void CgnsFile::initialize() {
	this->writeBase();
	this->writeZone();
	this->writeCoordinates();
	this->writeSections();
	this->writeBoundaryConditions();
}

void CgnsFile::writeField(const std::vector<double>& field, const std::string& fieldName) {
	if (cg_sol_write(this->fileIndex, this->baseIndex, this->zoneIndex, fieldName.c_str(), Vertex, &this->solutionIndex)) cg_error_exit();	
	if (cg_field_write(this->fileIndex, this->baseIndex, this->zoneIndex, this->solutionIndex, RealDouble, fieldName.c_str(), &field[0], &this->fieldIndex)) cg_error_exit();
}