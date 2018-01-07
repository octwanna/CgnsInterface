#ifndef CGNS_INTERFACE_CGNS_FILE_2D_HPP	
#define CGNS_INTERFACE_CGNS_FILE_2D_HPP

#include <iostream>
#include <string>
#include <vector>

#include <cgnslib.h>

#include <BoostInterface/Filesystem.hpp>
#include <Utilities/Vector.hpp>
#include <Grid/Grid.hpp>
#include <CgnsInterface/CgnsFile.hpp>

class CgnsFile2D : public CgnsFile {
	public:
		CgnsFile2D() = default;
		CgnsFile2D(const Grid&, const std::string&);

		~CgnsFile2D();

	private:
		void create() override;
		void writeZone() override;
		void writeCoordinates() override;
		void writeSections() override;
		void writeBoundaryConditions() override;
};

#endif