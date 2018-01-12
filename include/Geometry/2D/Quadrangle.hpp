#ifndef GEOMETRY_QUADRANGLE_HPP
#define GEOMETRY_QUADRANGLE_HPP

#include <Geometry/Node.hpp>
#include <Geometry/Geometry.hpp>
#include <Grid/Grid.hpp>

class Quadrangle : public Geometry {
	public:
		Quadrangle() = default;
		Quadrangle(const cgsize_t&, const cgsize_t&);

		~Quadrangle() = default;

	private:
		void calculateNumberOfNodes() override;
		void calculateNumberOfElements() override;
		void generateConnectivities() override;
		void generateBoundaries() override;
};

#endif