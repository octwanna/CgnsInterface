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

void CgnsFile::writeField(const std::vector<std::vector<double>>& field, const std::vector<double>& timeSteps, const std::string& fieldName) {
	if (field.size() != timeSteps.size()) throw std::runtime_error("field and timeSteps sizes mismatch.");
	this->solutionIndices.resize(field.size());
	this->fieldIndices.emplace_back(0);

	for (int i = 0; i < field.size(); i++) {
		std::string solutionName = std::string("TimeStep") + std::to_string(i+1);
		if (cg_sol_write(this->fileIndex, this->baseIndex, this->zoneIndex, solutionName.c_str(), Vertex, &this->solutionIndices[i])) cg_error_exit();
		if (cg_field_write(this->fileIndex, this->baseIndex, this->zoneIndex, this->solutionIndices[i], RealDouble, fieldName.c_str(), &field[i][0], &this->fieldIndices[i])) cg_error_exit();
	}
}