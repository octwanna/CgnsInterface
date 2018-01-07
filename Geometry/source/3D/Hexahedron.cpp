#include <Geometry/3D/Hexahedron.hpp>

Hexahedron::Hexahedron(const cgsize_t& numberOfNodesX, const cgsize_t& numberOfNodesY, const cgsize_t& numberOfNodesZ) : Geometry(numberOfNodesX, numberOfNodesY, numberOfNodesZ) {
	this->setConnectivity(8);
}

void Hexahedron::calculateNumberOfNodes() {
	this->numberOfNodes = this->numberOfNodesX * this->numberOfNodesY * this->numberOfNodesZ;
}

void Hexahedron::calculateNumberOfElements() {
	this->numberOfElements = (this->numberOfNodesX-1) * (this->numberOfNodesY-1) * (this->numberOfNodesZ-1);
}

void Hexahedron::generateConnectivities() {
    std::vector<std::vector<cgsize_t>> hexahedronConnectivity;
	for (cgsize_t k = 0; k < this->numberOfNodesZ-1; k++) {
		for (cgsize_t j = 0; j < this->numberOfNodesY-1; j++) {
			for (cgsize_t i = 0; i < this->numberOfNodesX-1; i++) {
				cgsize_t index = k*this->numberOfNodesX*this->numberOfNodesY + j*this->numberOfNodesX + i;
				hexahedronConnectivity.emplace_back(std::vector<cgsize_t>({
					this->indices[index], 
					this->indices[index + 1], 
					this->indices[index + 1 + this->numberOfNodesX], 
					this->indices[index + this->numberOfNodesX],
					this->indices[index + this->numberOfNodesX*this->numberOfNodesY], 
					this->indices[index + this->numberOfNodesX*this->numberOfNodesY + 1], 
					this->indices[index + this->numberOfNodesX*(1+this->numberOfNodesY) + 1], 
					this->indices[index + this->numberOfNodesX*(1+this->numberOfNodesY)]})
				);

			}
		}
	}
	this->grid.hexahedronConnectivity = std::move(hexahedronConnectivity);
}

void Hexahedron::generateBoundaries() {
	this->grid.boundaries.resize(6);

	cgsize_t x = this->numberOfNodesX - 1;
	cgsize_t y = this->numberOfNodesY - 1;
	cgsize_t z = this->numberOfNodesZ;
	Boundary westBoundary; westBoundary.name = "West";
	Boundary eastBoundary; eastBoundary.name = "East";
	for (cgsize_t k = 0; k < this->numberOfNodesZ-1; k++) {
		for (cgsize_t j = 0; j < this->numberOfNodesY-1; j++) {
			cgsize_t westIndex = j*x + k*x*y;
			std::vector<cgsize_t> temporary = this->grid.hexahedronConnectivity[westIndex];
			westBoundary.quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>{temporary[0], temporary[4], temporary[7], temporary[3]});

			cgsize_t eastIndex = this->numberOfNodesX - 2 + j*y + k*x*y;
			temporary = this->grid.hexahedronConnectivity[eastIndex];
			eastBoundary.quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>{temporary[1], temporary[2], temporary[6], temporary[5]});			
		}
	}
	x++; y++;
	std::vector<cgsize_t> westIndices(y*z);
	std::vector<cgsize_t> eastIndices(y*z);
	for (cgsize_t i = 0; i < z; i++) {
		for (cgsize_t j = 0; j < y; j++) {
			westIndices[j*z + i] = this->indices[i*x*y + j*x];
			eastIndices[j*z + i] = this->indices[i*x*y + j*x + (x-1)];
		}
	}
	westBoundary.nodeIndices = std::move(westIndices);
	eastBoundary.nodeIndices = std::move(eastIndices); 
	this->grid.boundaries[0] = std::move(westBoundary);
	this->grid.boundaries[1] = std::move(eastBoundary);
	x--; y--;

	Boundary southBoundary; southBoundary.name = "South";
	Boundary northBoundary; northBoundary.name = "North";
	for (cgsize_t k = 0; k < this->numberOfNodesZ-1; k++) {
		for (cgsize_t i = 0; i < this->numberOfNodesX-1; i++) {
			cgsize_t southIndex = i + k*x*y;
			std::vector<cgsize_t> temporary = this->grid.hexahedronConnectivity[southIndex];
			southBoundary.quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>{temporary[0], temporary[1], temporary[5], temporary[4]});

			cgsize_t northIndex = i + x*(this->numberOfNodesY-2) + k*x*y;
			temporary = this->grid.hexahedronConnectivity[northIndex];
			northBoundary.quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>{temporary[2], temporary[3], temporary[7], temporary[6]});
		}
	}
	x++; y++;
	std::vector<cgsize_t> southIndices(x*z);
	std::vector<cgsize_t> northIndices(x*z);	
	for (cgsize_t i = 0; i < z; i++) {
		for (cgsize_t k = 0; k < x; k++) {
			southIndices[i*x + k] = this->indices[i*x*y + k];
			northIndices[i*x + k] = this->indices[i*x*y + (y-1)*x + k];
		}
	} 
	southBoundary.nodeIndices = std::move(southIndices);
	northBoundary.nodeIndices = std::move(northIndices); 
	this->grid.boundaries[2]  = std::move(southBoundary);
	this->grid.boundaries[3]  = std::move(northBoundary);
	x--; y--;
	
	Boundary bottomBoundary; bottomBoundary.name = "Bottom";
	Boundary topBoundary;    topBoundary.name    = "Top";
    z -= 2;
    for (cgsize_t j = 0; j < this->numberOfNodesY-1; j++) {
		for (cgsize_t i = 0; i < this->numberOfNodesX-1; i++) {
			cgsize_t bottomIndex = i + j*x;
			std::vector<cgsize_t> temporary = this->grid.hexahedronConnectivity[bottomIndex];
			bottomBoundary.quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>{temporary[1], temporary[0], temporary[3], temporary[2]});

    		cgsize_t topIndex = i + j*x + x*y*z;
			temporary = this->grid.hexahedronConnectivity[topIndex];
			topBoundary.quadrilateralConnectivity.emplace_back(std::vector<cgsize_t>{temporary[4], temporary[5], temporary[6], temporary[7]});
    	}
    }
    x++; y++; z+=2;
	std::vector<cgsize_t> bottomIndices(x*z);
	std::vector<cgsize_t> topIndices(x*z);	    
    for (cgsize_t j = 0; j < y; j++) {
		for (cgsize_t k = 0; k < x; k++) {
			bottomIndices[j*x + k] = this->indices[j*x + k];
			topIndices[j*x + k]    = this->indices[(z-1)*x*y + j*x + k];
		}
	}
	bottomBoundary.nodeIndices = std::move(bottomIndices);
	topBoundary.nodeIndices    = std::move(topIndices); 	 
	this->grid.boundaries[4]   = std::move(bottomBoundary);
	this->grid.boundaries[5]   = std::move(topBoundary);	
}