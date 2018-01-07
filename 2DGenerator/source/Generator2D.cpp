#include <Geometry/Node.hpp>
#include <Geometry/2D/Quadrilateral.hpp>
#include <CgnsInterface/CgnsFile2D.hpp>

#include <stdexcept>
#include <string>
#include <cmath>

#define PI 3.14

int main(int argc, char** argv) {
	if (argc < 3) {
		throw std::runtime_error("Parameters are the number of nodes in X, Y directions.");
	}
	cgsize_t numberOfNodesX = std::stol(argv[1]);
	cgsize_t numberOfNodesY = std::stol(argv[2]);

	std::vector<std::vector<double>> nodes = determineNodes(numberOfNodesX, numberOfNodesY);
	Quadrilateral quadrilateral(numberOfNodesX, numberOfNodesY); quadrilateral.generateGrid();
	Grid grid = quadrilateral.getGrid();
	grid.coordinates = nodes; 
	grid.dimension = 2;

	CgnsFile2D cgnsFile2D(grid, "./"); cgnsFile2D.initialize(); 
	
	std::vector<double> temperatures(numberOfNodesX*numberOfNodesY);
	for (int i = 0; i < temperatures.size(); i++) temperatures[i] = sin(PI*nodes[i][0]) * sinh(PI*nodes[i][1]) / sinh(PI);
	cgnsFile2D.writeField(temperatures, "temperatures");

	return 0;
}