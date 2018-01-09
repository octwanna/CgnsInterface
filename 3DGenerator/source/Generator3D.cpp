#include <Geometry/Node.hpp>
#include <Geometry/3D/Hexahedron.hpp>
#include <CgnsInterface/CgnsFile3D.hpp>

#include <stdexcept>
#include <string>

int main(int argc, char** argv) {
	if (argc != 4) {
		throw std::runtime_error("Parameters are the number of nodes in X, Y, Z directions.");
	}
	cgsize_t numberOfNodesX = std::stol(argv[1]);
	cgsize_t numberOfNodesY = std::stol(argv[2]);
	cgsize_t numberOfNodesZ = std::stol(argv[3]);	

	std::vector<std::vector<double>> nodes = determineNodes(numberOfNodesX, numberOfNodesY, numberOfNodesZ);
	Hexahedron hexahedron(numberOfNodesX, numberOfNodesY, numberOfNodesZ); hexahedron.generateGrid();
	Grid grid = hexahedron.getGrid();
	grid.coordinates = nodes; 
	grid.dimension = 3;

	CgnsFile3D cgnsFile3D(grid, "/home/felipe/Downloads/"); cgnsFile3D.initialize(); 
	
	std::vector<double> density(numberOfNodesX*numberOfNodesY*numberOfNodesZ);
	for (int i = 0; i < density.size(); i++) density[i] = double(i*i);
	cgnsFile3D.writePermanentField(density, "density");

	return 0;
}