#include <Geometry/2D/Quadrilateral.hpp>

Quadrilateral::Quadrilateral(const cgsize_t& numberOfNodesX, const cgsize_t& numberOfNodesY) : Geometry(numberOfNodesX, numberOfNodesY, 0) {
	this->setConnectivity(4);
}

void Quadrilateral::calculateNumberOfNodes() {
	this->numberOfNodes = this->numberOfNodesX * this->numberOfNodesY;
}

void Quadrilateral::calculateNumberOfElements() {
	this->numberOfElements = (this->numberOfNodesX-1) * (this->numberOfNodesY-1);
}

void Quadrilateral::generateConnectivities() {
    std::vector<std::vector<cgsize_t>> quadrilateralConnectivity;
	for (cgsize_t i = 0; i < this->numberOfNodesY-1; i++) {
		for (cgsize_t j = 0; j < this->numberOfNodesX-1; j++) {
			quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>({
				this->indices[i*this->numberOfNodesX + j], 
				this->indices[i*this->numberOfNodesX + j + 1], 
				this->indices[i*this->numberOfNodesX + j + 1 + this->numberOfNodesX], 
				this->indices[i*this->numberOfNodesX + j + this->numberOfNodesX]})
			);
		}
	}
	this->grid.quadrilateralConnectivity = std::move(quadrilateralConnectivity);
}

void Quadrilateral::generateBoundaries() {
	this->grid.boundaries.resize(4);

	Boundary westBoundary; westBoundary.name = "West";
	Boundary eastBoundary; eastBoundary.name = "East";
	cgsize_t amountOfBoundaryLinesX = this->numberOfNodesX - 1;
	for (cgsize_t i = 0; i < amountOfBoundaryLinesX; i++) {
		westBoundary.lineConnectivity.emplace_back(std::vector<cgsize_t>{
			this->indices[this->numberOfNodes - (i+1)*this->numberOfNodesX], 
			this->indices[numberOfNodes - (i+2)*this->numberOfNodesX]});

		eastBoundary.lineConnectivity.emplace_back(std::vector<cgsize_t>{
			this->indices[i*this->numberOfNodesY+this->numberOfNodesX-1], 
			this->indices[i*this->numberOfNodesY+2*this->numberOfNodesX-1]});			
	}
	std::vector<cgsize_t> westIndices(this->numberOfNodesX);
	std::vector<cgsize_t> eastIndices(this->numberOfNodesX);
	for (cgsize_t i = 0; i < this->numberOfNodesY; i++) {
		westIndices[i] = this->indices[i*this->numberOfNodesX];
		eastIndices[i] = this->indices[i*this->numberOfNodesX + this->numberOfNodesX-1];
	}
	westBoundary.nodeIndices = std::move(westIndices);
	eastBoundary.nodeIndices = std::move(eastIndices); 
	this->grid.boundaries[0] = std::move(westBoundary);
	this->grid.boundaries[1] = std::move(eastBoundary);

	Boundary southBoundary; southBoundary.name = "South";
	Boundary northBoundary; northBoundary.name = "North";
	cgsize_t amountOfBoundaryLinesY = this->numberOfNodesY - 1;
	for (cgsize_t i = 0; i < amountOfBoundaryLinesY; i++) {
		southBoundary.lineConnectivity.push_back(std::vector<cgsize_t>{
			this->indices[i], 
			this->indices[i+1]});

		northBoundary.lineConnectivity.push_back(std::vector<cgsize_t>{
			this->indices[this->numberOfNodes-1-i], 
			this->indices[this->numberOfNodes-i-2]});
	}
	std::vector<cgsize_t> southIndices(this->numberOfNodesY);
	std::vector<cgsize_t> northIndices(this->numberOfNodesY);	
	for (cgsize_t i = 0; i < this->numberOfNodesX; i++) {
		southIndices[i] = indices[i];
		northIndices[i] = indices[this->numberOfNodesX*this->numberOfNodesY - this->numberOfNodesX + i];
	} 
	southBoundary.nodeIndices = std::move(southIndices);
	northBoundary.nodeIndices = std::move(northIndices); 
	this->grid.boundaries[2]  = std::move(southBoundary);
	this->grid.boundaries[3]  = std::move(northBoundary);
}