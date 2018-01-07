#ifndef GEOMETRY_QUADRILATERAL_HPP
#define GEOMETRY_QUADRILATERAL_HPP

#include <Geometry/Node.hpp>
#include <Geometry/Geometry.hpp>
#include <Grid/Grid.hpp>

class Quadrilateral : public Geometry {
	public:
		Quadrilateral() = default;
		Quadrilateral(const cgsize_t&, const cgsize_t&);

		~Quadrilateral() = default;

	private:
		void calculateNumberOfNodes() override;
		void calculateNumberOfElements() override;
		void generateConnectivities() override;
		void generateBoundaries() override;
};

#endif