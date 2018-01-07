#ifndef CGNS_INTERFACE_CGNS_FILE_3D_HPP	
#define CGNS_INTERFACE_CGNS_FILE_3D_HPP

#include <iostream>
#include <string>
#include <vector>

#include <cgnslib.h>

#include <BoostInterface/Filesystem.hpp>
#include <Utilities/Vector.hpp>
#include <Grid/Grid.hpp>
#include <CgnsInterface/CgnsFile.hpp>

class CgnsFile3D : public CgnsFile {
	public:
		CgnsFile3D() = default;
		CgnsFile3D(const Grid&, const std::string&);

		~CgnsFile3D();

	private:
		void create() override;
		void writeZone() override;
		void writeCoordinates() override;
		void writeSections() override;
		void writeBoundaryConditions() override;
};

#endif