#ifndef GEOMETRY_HEXAHEDRON_HPP
#define GEOMETRY_HEXAHEDRON_HPP

#include <Geometry/Node.hpp>
#include <Geometry/Geometry.hpp>
#include <Grid/Grid.hpp>

class Hexahedron : public Geometry {
	public:
		Hexahedron() = default;
		Hexahedron(const cgsize_t&, const cgsize_t&, const cgsize_t&);

		~Hexahedron() = default;

	private:
		void calculateNumberOfNodes() override;
		void calculateNumberOfElements() override;
		void generateConnectivities() override;
		void generateBoundaries() override;
};

#endif