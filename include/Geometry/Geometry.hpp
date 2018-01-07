#ifndef GEOMETRY_GEOMETRIES_HPP
#define GEOMETRY_GEOMETRIES_HPP

#include <iostream>
#include <vector>

#include <cgnslib.h>

#include <Geometry/Node.hpp>
#include <Grid/Grid.hpp>
#include <Utilities/Vector.hpp>

class Geometry {
	public:
		Geometry() = default;
		Geometry(const cgsize_t&, const cgsize_t&, const cgsize_t&);

		void setNumberOfNodesX(const cgsize_t&);
		cgsize_t getNumberOfNodesX() const;
		
		void setNumberOfNodesY(const cgsize_t&);
		cgsize_t getNumberOfNodesY() const;
		
		void setNumberOfNodesZ(const cgsize_t&);
		cgsize_t getNumberOfNodesZ() const;

		cgsize_t getConnectivity() const;

		cgsize_t getNumberOfNodes() const;

		cgsize_t getNumberOfElements() const;

		void generateGrid();
		Grid getGrid() const;

		~Geometry() = default;

	protected:
		virtual void calculateNumberOfNodes() = 0;
		virtual void calculateNumberOfElements() = 0;
		void generateIndices();
		virtual void generateConnectivities() = 0;
		virtual void generateBoundaries() = 0;
		void setConnectivity(const cgsize_t&);
		
		cgsize_t numberOfNodesX;
		cgsize_t numberOfNodesY;
		cgsize_t numberOfNodesZ;
		cgsize_t connectivity;
		cgsize_t numberOfNodes;
		cgsize_t numberOfElements;
		std::vector<cgsize_t> indices;
		Grid grid;
};

#endif