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

	CgnsFile2D cgnsFile2D(grid, "/home/felipe/Downloads/"); cgnsFile2D.initialize(); 
	
	std::vector<double> temperature(numberOfNodesX*numberOfNodesY);
	for (int i = 0; i < temperature.size(); i++) temperature[i] = sin(PI*nodes[i][0]) * sinh(PI*nodes[i][1]) / sinh(PI);
	cgnsFile2D.writeField(temperature, "temperature");

	std::vector<std::vector<double>> densities;
	std::vector<double> timeStep(10);
	for (int i = 0; i < timeStep.size(); i++) {
		timeStep[i] = i * 0.1;
		std::vector<double> density(numberOfNodesX*numberOfNodesY);
		for (int j = 0; j < numberOfNodesX*numberOfNodesY; j++) {
			density[j] = timeStep[i] * j * j;
		}
		densities.push_back(density);
	}
	cgnsFile2D.writeField(densities, timeStep, "densities");
	
	std::cout << std::endl << "\tdensities" << std::endl;
	for (auto i = densities.cbegin(); i < densities.cend(); i++) {
		for (auto j = i->cbegin(); j < i->cend(); j++) {
			std::cout << "\t" << *j;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "\ttimeStep" << std::endl;
	for (auto i = timeStep.cbegin(); i < timeStep.cend(); i++) std::cout << "\t" << *i;
	std::cout << std::endl;


	return 0;
}