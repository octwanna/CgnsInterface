#ifndef GEOMETRY_NODE_HPP
#define GEOMETRY_NODE_HPP

#include <iostream>
#include <vector>

#include <cgnslib.h>

std::vector<std::vector<double>> determineNodes(const cgsize_t&, const cgsize_t&, const cgsize_t&);

std::vector<std::vector<double>> determineNodes(const cgsize_t&, const cgsize_t&);

#endif