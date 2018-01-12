#define BOOST_TEST_MODULE GeometryTestModule

#include <BoostInterface/Test.hpp>
#include <Geometry/Node.hpp>
#include <Geometry/3D/Hexahedron.hpp>
#include <Geometry/2D/Quadrangle.hpp>

#define TOLERANCE 1e-12

struct HexahedronFixture {
	HexahedronFixture() {
		this->numberOfNodesX = 3;
		this->numberOfNodesY = 3;
		this->numberOfNodesZ = 3;
		this->nodes = determineNodes(this->numberOfNodesX, this->numberOfNodesY, this->numberOfNodesZ);
		this->hexahedron = Hexahedron(this->numberOfNodesX, this->numberOfNodesY, this->numberOfNodesZ);
		this->hexahedron.generateGrid();
		this->grid = hexahedron.getGrid();
	}

	~HexahedronFixture() = default;

	cgsize_t numberOfNodesX;
	cgsize_t numberOfNodesY;
	cgsize_t numberOfNodesZ;
	std::vector<std::vector<double>> nodes;
	Hexahedron hexahedron;
	Grid grid;
};

FixtureTestSuite(Geometry3DTestModule, HexahedronFixture)

TestCase(Nodes3D) {
	checkEqual(this->nodes.size(), 27);

	checkClose(this->nodes[0][0], 0.0, TOLERANCE);
	checkClose(this->nodes[0][1], 0.0, TOLERANCE);
	checkClose(this->nodes[0][2], 0.0, TOLERANCE);

	checkClose(this->nodes[1][0], 0.5, TOLERANCE);
	checkClose(this->nodes[1][1], 0.0, TOLERANCE);
	checkClose(this->nodes[1][2], 0.0, TOLERANCE);

	checkClose(this->nodes[2][0], 1.0, TOLERANCE);
	checkClose(this->nodes[2][1], 0.0, TOLERANCE);
	checkClose(this->nodes[2][2], 0.0, TOLERANCE);
	
	checkClose(this->nodes[3][0], 0.0, TOLERANCE);
	checkClose(this->nodes[3][1], 0.5, TOLERANCE);
	checkClose(this->nodes[3][2], 0.0, TOLERANCE);
	
	checkClose(this->nodes[4][0], 0.5, TOLERANCE);
	checkClose(this->nodes[4][1], 0.5, TOLERANCE);
	checkClose(this->nodes[4][2], 0.0, TOLERANCE);

	checkClose(this->nodes[5][0], 1.0, TOLERANCE);
	checkClose(this->nodes[5][1], 0.5, TOLERANCE);
	checkClose(this->nodes[5][2], 0.0, TOLERANCE);

	checkClose(this->nodes[6][0], 0.0, TOLERANCE);
	checkClose(this->nodes[6][1], 1.0, TOLERANCE);
	checkClose(this->nodes[6][2], 0.0, TOLERANCE);

	checkClose(this->nodes[7][0], 0.5, TOLERANCE);
	checkClose(this->nodes[7][1], 1.0, TOLERANCE);
	checkClose(this->nodes[7][2], 0.0, TOLERANCE);

	checkClose(this->nodes[8][0], 1.0, TOLERANCE);
	checkClose(this->nodes[8][1], 1.0, TOLERANCE);
	checkClose(this->nodes[8][2], 0.0, TOLERANCE);

	checkClose(this->nodes[9][0], 0.0, TOLERANCE);
	checkClose(this->nodes[9][1], 0.0, TOLERANCE);
	checkClose(this->nodes[9][2], 0.5, TOLERANCE);

	checkClose(this->nodes[10][0], 0.5, TOLERANCE);
	checkClose(this->nodes[10][1], 0.0, TOLERANCE);
	checkClose(this->nodes[10][2], 0.5, TOLERANCE);
	
	checkClose(this->nodes[11][0], 1.0, TOLERANCE);
	checkClose(this->nodes[11][1], 0.0, TOLERANCE);
	checkClose(this->nodes[11][2], 0.5, TOLERANCE);
	
	checkClose(this->nodes[12][0], 0.0, TOLERANCE);
	checkClose(this->nodes[12][1], 0.5, TOLERANCE);
	checkClose(this->nodes[12][2], 0.5, TOLERANCE);
	
	checkClose(this->nodes[13][0], 0.5, TOLERANCE);
	checkClose(this->nodes[13][1], 0.5, TOLERANCE);
	checkClose(this->nodes[13][2], 0.5, TOLERANCE);
	
	checkClose(this->nodes[14][0], 1.0, TOLERANCE);
	checkClose(this->nodes[14][1], 0.5, TOLERANCE);
	checkClose(this->nodes[14][2], 0.5, TOLERANCE);
	
	checkClose(this->nodes[15][0], 0.0, TOLERANCE);
	checkClose(this->nodes[15][1], 1.0, TOLERANCE);
	checkClose(this->nodes[15][2], 0.5, TOLERANCE);
	
	checkClose(this->nodes[16][0], 0.5, TOLERANCE);
	checkClose(this->nodes[16][1], 1.0, TOLERANCE);
	checkClose(this->nodes[16][2], 0.5, TOLERANCE);

	checkClose(this->nodes[17][0], 1.0, TOLERANCE);
	checkClose(this->nodes[17][1], 1.0, TOLERANCE);
	checkClose(this->nodes[17][2], 0.5, TOLERANCE);	

	checkClose(this->nodes[18][0], 0.0, TOLERANCE);
	checkClose(this->nodes[18][1], 0.0, TOLERANCE);
	checkClose(this->nodes[18][2], 1.0, TOLERANCE);

	checkClose(this->nodes[19][0], 0.5, TOLERANCE);
	checkClose(this->nodes[19][1], 0.0, TOLERANCE);
	checkClose(this->nodes[19][2], 1.0, TOLERANCE);
	
	checkClose(this->nodes[20][0], 1.0, TOLERANCE);
	checkClose(this->nodes[20][1], 0.0, TOLERANCE);
	checkClose(this->nodes[20][2], 1.0, TOLERANCE);
	
	checkClose(this->nodes[21][0], 0.0, TOLERANCE);
	checkClose(this->nodes[21][1], 0.5, TOLERANCE);
	checkClose(this->nodes[21][2], 1.0, TOLERANCE);
	
	checkClose(this->nodes[22][0], 0.5, TOLERANCE);
	checkClose(this->nodes[22][1], 0.5, TOLERANCE);
	checkClose(this->nodes[22][2], 1.0, TOLERANCE);
	
	checkClose(this->nodes[23][0], 1.0, TOLERANCE);
	checkClose(this->nodes[23][1], 0.5, TOLERANCE);
	checkClose(this->nodes[23][2], 1.0, TOLERANCE);
	
	checkClose(this->nodes[24][0], 0.0, TOLERANCE);
	checkClose(this->nodes[24][1], 1.0, TOLERANCE);
	checkClose(this->nodes[24][2], 1.0, TOLERANCE);
	
	checkClose(this->nodes[25][0], 0.5, TOLERANCE);
	checkClose(this->nodes[25][1], 1.0, TOLERANCE);
	checkClose(this->nodes[25][2], 1.0, TOLERANCE);

	checkClose(this->nodes[26][0], 1.0, TOLERANCE);
	checkClose(this->nodes[26][1], 1.0, TOLERANCE);
	checkClose(this->nodes[26][2], 1.0, TOLERANCE);	
}

TestCase(Hexahedra) {
	auto connectivities = this->grid.hexahedronConnectivity;

	checkEqual(connectivities[0][0],  1);
	checkEqual(connectivities[0][1],  2);
	checkEqual(connectivities[0][2],  5);
	checkEqual(connectivities[0][3],  4);
	checkEqual(connectivities[0][4], 10);
	checkEqual(connectivities[0][5], 11);
	checkEqual(connectivities[0][6], 14);
	checkEqual(connectivities[0][7], 13);

	checkEqual(connectivities[1][0],  2);
	checkEqual(connectivities[1][1],  3);
	checkEqual(connectivities[1][2],  6);
	checkEqual(connectivities[1][3],  5);
	checkEqual(connectivities[1][4], 11);
	checkEqual(connectivities[1][5], 12);
	checkEqual(connectivities[1][6], 15);
	checkEqual(connectivities[1][7], 14);	

	checkEqual(connectivities[2][0],  4);
	checkEqual(connectivities[2][1],  5);
	checkEqual(connectivities[2][2],  8);
	checkEqual(connectivities[2][3],  7);
	checkEqual(connectivities[2][4], 13);
	checkEqual(connectivities[2][5], 14);
	checkEqual(connectivities[2][6], 17);
	checkEqual(connectivities[2][7], 16);		

	checkEqual(connectivities[3][0],  5);
	checkEqual(connectivities[3][1],  6);
	checkEqual(connectivities[3][2],  9);
	checkEqual(connectivities[3][3],  8);
	checkEqual(connectivities[3][4], 14);
	checkEqual(connectivities[3][5], 15);
	checkEqual(connectivities[3][6], 18);
	checkEqual(connectivities[3][7], 17);	

	checkEqual(connectivities[4][0], 10);
	checkEqual(connectivities[4][1], 11);
	checkEqual(connectivities[4][2], 14);
	checkEqual(connectivities[4][3], 13);
	checkEqual(connectivities[4][4], 19);
	checkEqual(connectivities[4][5], 20);
	checkEqual(connectivities[4][6], 23);
	checkEqual(connectivities[4][7], 22);

	checkEqual(connectivities[5][0], 11);
	checkEqual(connectivities[5][1], 12);
	checkEqual(connectivities[5][2], 15);
	checkEqual(connectivities[5][3], 14);
	checkEqual(connectivities[5][4], 20);
	checkEqual(connectivities[5][5], 21);
	checkEqual(connectivities[5][6], 24);
	checkEqual(connectivities[5][7], 23);	

	checkEqual(connectivities[6][0], 13);
	checkEqual(connectivities[6][1], 14);
	checkEqual(connectivities[6][2], 17);
	checkEqual(connectivities[6][3], 16);
	checkEqual(connectivities[6][4], 22);
	checkEqual(connectivities[6][5], 23);
	checkEqual(connectivities[6][6], 26);
	checkEqual(connectivities[6][7], 25);		

	checkEqual(connectivities[7][0], 14);
	checkEqual(connectivities[7][1], 15);
	checkEqual(connectivities[7][2], 18);
	checkEqual(connectivities[7][3], 17);
	checkEqual(connectivities[7][4], 23);
	checkEqual(connectivities[7][5], 24);
	checkEqual(connectivities[7][6], 27);
	checkEqual(connectivities[7][7], 26);			
}

TestCase(WestBoundary) {
	Boundary boundary = this->grid.boundaries[0];
	checkEqual(boundary.quadrangleConnectivity[0][0],  1); checkEqual(boundary.quadrangleConnectivity[0][1], 10); checkEqual(boundary.quadrangleConnectivity[0][2], 13); checkEqual(boundary.quadrangleConnectivity[0][3],  4);
	checkEqual(boundary.quadrangleConnectivity[1][0],  4); checkEqual(boundary.quadrangleConnectivity[1][1], 13); checkEqual(boundary.quadrangleConnectivity[1][2], 16); checkEqual(boundary.quadrangleConnectivity[1][3],  7);
	checkEqual(boundary.quadrangleConnectivity[2][0], 10); checkEqual(boundary.quadrangleConnectivity[2][1], 19); checkEqual(boundary.quadrangleConnectivity[2][2], 22); checkEqual(boundary.quadrangleConnectivity[2][3], 13);
	checkEqual(boundary.quadrangleConnectivity[3][0], 13); checkEqual(boundary.quadrangleConnectivity[3][1], 22); checkEqual(boundary.quadrangleConnectivity[3][2], 25); checkEqual(boundary.quadrangleConnectivity[3][3], 16);

	checkClose(nodes[boundary.nodeIndices[0]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[3]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[4]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[5]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[6]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[7]-1][0], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[8]-1][0], 0.0, TOLERANCE);
}

TestCase(EastBoundary) {
	Boundary boundary = this->grid.boundaries[1];
	checkEqual(boundary.quadrangleConnectivity[0][0],  3); checkEqual(boundary.quadrangleConnectivity[0][1],  6); checkEqual(boundary.quadrangleConnectivity[0][2], 15); checkEqual(boundary.quadrangleConnectivity[0][3], 12);
	checkEqual(boundary.quadrangleConnectivity[1][0],  6); checkEqual(boundary.quadrangleConnectivity[1][1],  9); checkEqual(boundary.quadrangleConnectivity[1][2], 18); checkEqual(boundary.quadrangleConnectivity[1][3], 15);
	checkEqual(boundary.quadrangleConnectivity[2][0], 12); checkEqual(boundary.quadrangleConnectivity[2][1], 15); checkEqual(boundary.quadrangleConnectivity[2][2], 24); checkEqual(boundary.quadrangleConnectivity[2][3], 21);
	checkEqual(boundary.quadrangleConnectivity[3][0], 15); checkEqual(boundary.quadrangleConnectivity[3][1], 18); checkEqual(boundary.quadrangleConnectivity[3][2], 27); checkEqual(boundary.quadrangleConnectivity[3][3], 24);

	checkClose(nodes[boundary.nodeIndices[0]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[3]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[4]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[5]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[6]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[7]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[8]-1][0], 1.0, TOLERANCE);
}

TestCase(SouthBoundary) {
	Boundary boundary = this->grid.boundaries[2];
	checkEqual(boundary.quadrangleConnectivity[0][0],  1); checkEqual(boundary.quadrangleConnectivity[0][1],  2); checkEqual(boundary.quadrangleConnectivity[0][2], 11); checkEqual(boundary.quadrangleConnectivity[0][3], 10);
	checkEqual(boundary.quadrangleConnectivity[1][0],  2); checkEqual(boundary.quadrangleConnectivity[1][1],  3); checkEqual(boundary.quadrangleConnectivity[1][2], 12); checkEqual(boundary.quadrangleConnectivity[1][3], 11);
	checkEqual(boundary.quadrangleConnectivity[2][0], 10); checkEqual(boundary.quadrangleConnectivity[2][1], 11); checkEqual(boundary.quadrangleConnectivity[2][2], 20); checkEqual(boundary.quadrangleConnectivity[2][3], 19);
	checkEqual(boundary.quadrangleConnectivity[3][0], 11); checkEqual(boundary.quadrangleConnectivity[3][1], 12); checkEqual(boundary.quadrangleConnectivity[3][2], 21); checkEqual(boundary.quadrangleConnectivity[3][3], 20);

	checkClose(nodes[boundary.nodeIndices[0]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[3]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[4]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[5]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[6]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[7]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[8]-1][1], 0.0, TOLERANCE);	
}

TestCase(NorthBoundary) {
	Boundary boundary = this->grid.boundaries[3];
	checkEqual(boundary.quadrangleConnectivity[0][0],  8); checkEqual(boundary.quadrangleConnectivity[0][1],  7); checkEqual(boundary.quadrangleConnectivity[0][2], 16); checkEqual(boundary.quadrangleConnectivity[0][3], 17);
	checkEqual(boundary.quadrangleConnectivity[1][0],  9); checkEqual(boundary.quadrangleConnectivity[1][1],  8); checkEqual(boundary.quadrangleConnectivity[1][2], 17); checkEqual(boundary.quadrangleConnectivity[1][3], 18);
	checkEqual(boundary.quadrangleConnectivity[2][0], 17); checkEqual(boundary.quadrangleConnectivity[2][1], 16); checkEqual(boundary.quadrangleConnectivity[2][2], 25); checkEqual(boundary.quadrangleConnectivity[2][3], 26);
	checkEqual(boundary.quadrangleConnectivity[3][0], 18); checkEqual(boundary.quadrangleConnectivity[3][1], 17); checkEqual(boundary.quadrangleConnectivity[3][2], 26); checkEqual(boundary.quadrangleConnectivity[3][3], 27);
	
	checkClose(nodes[boundary.nodeIndices[0]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[3]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[4]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[5]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[6]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[7]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[8]-1][1], 1.0, TOLERANCE);	
}

TestCase(BottomBoundary) {
	Boundary boundary = this->grid.boundaries[4];
	checkEqual(boundary.quadrangleConnectivity[0][0], 2); checkEqual(boundary.quadrangleConnectivity[0][1], 1); checkEqual(boundary.quadrangleConnectivity[0][2], 4); checkEqual(boundary.quadrangleConnectivity[0][3], 5);
	checkEqual(boundary.quadrangleConnectivity[1][0], 3); checkEqual(boundary.quadrangleConnectivity[1][1], 2); checkEqual(boundary.quadrangleConnectivity[1][2], 5); checkEqual(boundary.quadrangleConnectivity[1][3], 6);
	checkEqual(boundary.quadrangleConnectivity[2][0], 5); checkEqual(boundary.quadrangleConnectivity[2][1], 4); checkEqual(boundary.quadrangleConnectivity[2][2], 7); checkEqual(boundary.quadrangleConnectivity[2][3], 8);
	checkEqual(boundary.quadrangleConnectivity[3][0], 6); checkEqual(boundary.quadrangleConnectivity[3][1], 5); checkEqual(boundary.quadrangleConnectivity[3][2], 8); checkEqual(boundary.quadrangleConnectivity[3][3], 9);
	
	checkClose(nodes[boundary.nodeIndices[0]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[3]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[4]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[5]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[6]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[7]-1][2], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[8]-1][2], 0.0, TOLERANCE);	
}

TestCase(TopBoundary) {
	Boundary boundary = this->grid.boundaries[5];
	checkEqual(boundary.quadrangleConnectivity[0][0], 19); checkEqual(boundary.quadrangleConnectivity[0][1], 20); checkEqual(boundary.quadrangleConnectivity[0][2], 23); checkEqual(boundary.quadrangleConnectivity[0][3], 22);
	checkEqual(boundary.quadrangleConnectivity[1][0], 20); checkEqual(boundary.quadrangleConnectivity[1][1], 21); checkEqual(boundary.quadrangleConnectivity[1][2], 24); checkEqual(boundary.quadrangleConnectivity[1][3], 23);
	checkEqual(boundary.quadrangleConnectivity[2][0], 22); checkEqual(boundary.quadrangleConnectivity[2][1], 23); checkEqual(boundary.quadrangleConnectivity[2][2], 26); checkEqual(boundary.quadrangleConnectivity[2][3], 25);
	checkEqual(boundary.quadrangleConnectivity[3][0], 23); checkEqual(boundary.quadrangleConnectivity[3][1], 24); checkEqual(boundary.quadrangleConnectivity[3][2], 27); checkEqual(boundary.quadrangleConnectivity[3][3], 26);
	
	checkClose(nodes[boundary.nodeIndices[0]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[3]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[4]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[5]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[6]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[7]-1][2], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[8]-1][2], 1.0, TOLERANCE);	
}

TestSuiteEnd()

struct QuadrilateralFixture {
	QuadrilateralFixture() {
		this->numberOfNodesX = 3;
		this->numberOfNodesY = 3;
		this->nodes = determineNodes(this->numberOfNodesX, this->numberOfNodesY);
		this->quadrangle = Quadrangle(this->numberOfNodesX, this->numberOfNodesY);
		this->quadrangle.generateGrid();
		this->grid = quadrangle.getGrid();
	}

	~QuadrilateralFixture() = default;

	cgsize_t numberOfNodesX;
	cgsize_t numberOfNodesY;
	std::vector<std::vector<double>> nodes;
	Quadrangle quadrangle;
	Grid grid;
};

FixtureTestSuite(Geometry2DTestModule, QuadrilateralFixture)

TestCase(Nodes2D) {
	checkEqual(this->nodes.size(), 9);

	checkClose(this->nodes[0][0], 0.0, TOLERANCE);
	checkClose(this->nodes[0][1], 0.0, TOLERANCE);
	checkClose(this->nodes[0][2], 0.0, TOLERANCE);

	checkClose(this->nodes[1][0], 0.5, TOLERANCE);
	checkClose(this->nodes[1][1], 0.0, TOLERANCE);
	checkClose(this->nodes[1][2], 0.0, TOLERANCE);

	checkClose(this->nodes[2][0], 1.0, TOLERANCE);
	checkClose(this->nodes[2][1], 0.0, TOLERANCE);
	checkClose(this->nodes[2][2], 0.0, TOLERANCE);
	
	checkClose(this->nodes[3][0], 0.0, TOLERANCE);
	checkClose(this->nodes[3][1], 0.5, TOLERANCE);
	checkClose(this->nodes[3][2], 0.0, TOLERANCE);
	
	checkClose(this->nodes[4][0], 0.5, TOLERANCE);
	checkClose(this->nodes[4][1], 0.5, TOLERANCE);
	checkClose(this->nodes[4][2], 0.0, TOLERANCE);

	checkClose(this->nodes[5][0], 1.0, TOLERANCE);
	checkClose(this->nodes[5][1], 0.5, TOLERANCE);
	checkClose(this->nodes[5][2], 0.0, TOLERANCE);

	checkClose(this->nodes[6][0], 0.0, TOLERANCE);
	checkClose(this->nodes[6][1], 1.0, TOLERANCE);
	checkClose(this->nodes[6][2], 0.0, TOLERANCE);

	checkClose(this->nodes[7][0], 0.5, TOLERANCE);
	checkClose(this->nodes[7][1], 1.0, TOLERANCE);
	checkClose(this->nodes[7][2], 0.0, TOLERANCE);

	checkClose(this->nodes[8][0], 1.0, TOLERANCE);
	checkClose(this->nodes[8][1], 1.0, TOLERANCE);
	checkClose(this->nodes[8][2], 0.0, TOLERANCE);
}

TestCase(Quadrilaterals) {
	auto connectivities = this->grid.quadrangleConnectivity;

	checkEqual(connectivities[0][0],  1);
	checkEqual(connectivities[0][1],  2);
	checkEqual(connectivities[0][2],  5);
	checkEqual(connectivities[0][3],  4);

	checkEqual(connectivities[1][0],  2);
	checkEqual(connectivities[1][1],  3);
	checkEqual(connectivities[1][2],  6);
	checkEqual(connectivities[1][3],  5);

	checkEqual(connectivities[2][0],  4);
	checkEqual(connectivities[2][1],  5);
	checkEqual(connectivities[2][2],  8);
	checkEqual(connectivities[2][3],  7);

	checkEqual(connectivities[3][0],  5);
	checkEqual(connectivities[3][1],  6);
	checkEqual(connectivities[3][2],  9);
	checkEqual(connectivities[3][3],  8);
}

TestCase(WestBoundary) {
	Boundary boundary = this->grid.boundaries[0];
	checkEqual(boundary.lineConnectivity[0][0],  7); checkEqual(boundary.lineConnectivity[0][1], 4);
	checkEqual(boundary.lineConnectivity[1][0],  4); checkEqual(boundary.lineConnectivity[1][1], 1);

	checkClose(this->nodes[boundary.nodeIndices[0]-1][0], 0.0, TOLERANCE);
	checkClose(this->nodes[boundary.nodeIndices[1]-1][0], 0.0, TOLERANCE);
	checkClose(this->nodes[boundary.nodeIndices[2]-1][0], 0.0, TOLERANCE);
}

TestCase(EastBoundary) {
	Boundary boundary = this->grid.boundaries[1];
	checkEqual(boundary.lineConnectivity[0][0],  3); checkEqual(boundary.lineConnectivity[0][1],  6); 
	checkEqual(boundary.lineConnectivity[1][0],  6); checkEqual(boundary.lineConnectivity[1][1],  9); 

	checkClose(nodes[boundary.nodeIndices[0]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][0], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][0], 1.0, TOLERANCE);
}

TestCase(SouthBoundary) {
	Boundary boundary = this->grid.boundaries[2];
	checkEqual(boundary.lineConnectivity[0][0],  1); checkEqual(boundary.lineConnectivity[0][1],  2);
	checkEqual(boundary.lineConnectivity[1][0],  2); checkEqual(boundary.lineConnectivity[1][1],  3);

	checkClose(nodes[boundary.nodeIndices[0]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][1], 0.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][1], 0.0, TOLERANCE);
}

TestCase(NorthBoundary) {
	Boundary boundary = this->grid.boundaries[3];
	checkEqual(boundary.lineConnectivity[0][0],  9); checkEqual(boundary.lineConnectivity[0][1],  8); 
	checkEqual(boundary.lineConnectivity[1][0],  8); checkEqual(boundary.lineConnectivity[1][1],  7); 
	
	checkClose(nodes[boundary.nodeIndices[0]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[1]-1][1], 1.0, TOLERANCE);
	checkClose(nodes[boundary.nodeIndices[2]-1][1], 1.0, TOLERANCE);
}

TestSuiteEnd()