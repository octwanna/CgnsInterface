#define BOOST_TEST_MODULE UtilitiesTestModule

#include <BoostInterface/Test.hpp>
#include <Utilities/Vector.hpp>

#define TOLERANCE 1e-12

TestSuite(Vector)
	TestCase(Vector1DToArray1D) {
		std::vector<int> a = {0, 1, 2, 3};
		int* b = determine_array_1d(a);
		
		checkEqual(b[0], 0); checkEqual(b[1], 1); checkEqual(b[2], 2); checkEqual(b[3], 3);
	
		delete b;
	}

	TestCase(Vector2DToArray1D) {
		std::vector<std::vector<int>> a = {{0, 1}, {2, 3}};
		int* b = determine_array_1d(a);
	
		checkEqual(b[0], 0); checkEqual(b[1], 1); checkEqual(b[2], 2); checkEqual(b[3], 3); 
	
		delete b;
	}

	TestCase(Vector2DToArray2D) {
		std::vector<std::vector<int>> a = {{0, 1}, {2, 3}};
		int** b = determine_array_2d(a);
	
		checkEqual(b[0][0], 0); checkEqual(b[0][1], 1); 
		checkEqual(b[1][0], 2); checkEqual(b[1][1], 3); 
	
		for (int i = 0; i < a.size(); i++) {
			delete b[i];
		}
		delete b;
	}
	
	TestCase(Vector2DToVector1D) {

	}		
	
	TestCase(Vector1DToVector2D) {

	}
TestSuiteEnd()