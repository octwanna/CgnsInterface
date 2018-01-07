#ifndef GRID_GRID_HPP
#define GRID_GRID_HPP
	
#include <cgnslib.h>

struct Boundary {
	std::string	name;	
	std::vector<std::vector<cgsize_t>> quadrilateralConnectivity;	
	std::vector<std::vector<cgsize_t>> lineConnectivity;	
	std::vector<cgsize_t> nodeIndices;		
};

struct Grid {
	cgsize_t dimension;		
	std::vector<std::vector<double>> coordinates;	
	std::vector<Boundary> boundaries; 
	std::vector<std::vector<cgsize_t>> hexahedronConnectivity;		
	std::vector<std::vector<cgsize_t>> quadrilateralConnectivity;		
};

#endif