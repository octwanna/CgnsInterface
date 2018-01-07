#include <Geometry/Node.hpp>

std::vector<std::vector<double>> determineNodes(const cgsize_t& numberOfNodesX, const cgsize_t& numberOfNodesY, const cgsize_t& numberOfNodesZ) {
	std::vector<std::vector<double>> nodes;
	double paceX = 1.0 / double(numberOfNodesX-1);
    double paceY = 1.0 / double(numberOfNodesY-1);
    double paceZ = 1.0 / double(numberOfNodesZ-1);
	for (cgsize_t k = 1; k < numberOfNodesZ+1; k++) {
		for (cgsize_t j = 1; j < numberOfNodesY+1; j++) {
			for (cgsize_t i = 1; i < numberOfNodesX+1; i++) {
				double x = (i-1)*paceX;
				double y = (j-1)*paceY;
				double z = (k-1)*paceZ;
				nodes.emplace_back(std::vector<double>({x, y, z}));
			}
		}
	}
	return nodes;
}

std::vector<std::vector<double>> determineNodes(const cgsize_t& numberOfNodesX, const cgsize_t& numberOfNodesY) {
	std::vector<std::vector<double>> nodes;
	double paceX = 1.0 / double(numberOfNodesX-1);
    double paceY = 1.0 / double(numberOfNodesY-1);
	for (cgsize_t j = 1; j < numberOfNodesY+1; j++) {
		for (cgsize_t i = 1; i < numberOfNodesX+1; i++) {
			double x = (i-1)*paceX;
			double y = (j-1)*paceY;
			nodes.emplace_back(std::vector<double>({x, y, 0.0}));
		}
	}
	return nodes;
}