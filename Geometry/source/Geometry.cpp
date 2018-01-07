#include <Geometry/Geometry.hpp>

Geometry::Geometry(const cgsize_t& numberOfNodesX, const cgsize_t& numberOfNodesY, const cgsize_t& numberOfNodesZ) {
	this->setNumberOfNodesX(numberOfNodesX); 
	this->setNumberOfNodesY(numberOfNodesY); 
	this->setNumberOfNodesZ(numberOfNodesZ);
}

void Geometry::setNumberOfNodesX(const cgsize_t& numberOfNodesX) {
	this->numberOfNodesX = numberOfNodesX;
}

cgsize_t Geometry::getNumberOfNodesX() const {
	return this->numberOfNodesX;
}

void Geometry::setNumberOfNodesY(const cgsize_t& numberOfNodesY) {
	this->numberOfNodesY = numberOfNodesY;
}

cgsize_t Geometry::getNumberOfNodesY() const {
	return this->numberOfNodesY;
}

void Geometry::setNumberOfNodesZ(const cgsize_t& numberOfNodesZ) {
	this->numberOfNodesZ = numberOfNodesZ;
}

cgsize_t Geometry::getNumberOfNodesZ() const {
	return this->numberOfNodesZ;
}

void Geometry::setConnectivity(const cgsize_t& connectivity) {
	this->connectivity = connectivity;
}

cgsize_t Geometry::getConnectivity() const {
	return this->connectivity;
}

cgsize_t Geometry::getNumberOfNodes() const {
	return this->numberOfNodes;
}

cgsize_t Geometry::getNumberOfElements() const {
	return this->numberOfElements;
}

void Geometry::generateIndices() {
	this->indices.resize(this->numberOfNodes);
	for (cgsize_t i = 0; i < this->numberOfNodes; i++) this->indices[i] = i + 1;
}

void Geometry::generateGrid() {
	this->calculateNumberOfNodes();
	this->calculateNumberOfElements();
	this->generateIndices();
	this->generateConnectivities();
	this->generateBoundaries();
}

Grid Geometry::getGrid() const {
	return this->grid;
}