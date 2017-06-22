#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
using namespace std;

double triangle_area(int s) {
	//Precondition: s is an integer side length of value greater than 0.
	//Postcondition: Returns the area of the triangle as a double.
	assert(s >= 0);
	double a = (sqrt(3) / 4) * (s * s);
	return a;
}

double square_area(int s) {
	//Precondition: s is an integer side length of value greater than 0.
	//Postcondition: Returns the area of the square as a double.
	assert(s >= 0);
	return s * s;
}

double pentagon_area(int s) {
	//Precondition: s is an integer side length of value greater than 0.
	//Postcondition: Returns the area of a pentagon as a double;
	assert(s >= 0);
	double pent_const = sqrt(5 * (5 + 2 * sqrt(5))) / 4;
	return pent_const * s * s;
}

double hexagon_area(int s) {
	//Precondition: s is an integer side length of value greater than 0.
	//Postcondition: Returns the area of a hexagon as a double;
	assert(s >= 0);
	double hex_const = 3 * sqrt(3) / 2;
	return hex_const * s * s;
}

double heptagon_area(int s) {
	//Precondition: s is an integer side length of value greater than 0.
	//Postcondition: Returns the area of a heptagon as a double;
	assert(s >= 0);
	double hept_const = 7 / (4 * tan(M_PI / 7));
	return hept_const * s * s;
}

double octagon_area(int s) {
	//Precondition: s is an integer side length of value greater than 0.
	//Postcondition: Returns the area of a octagon as a double;
	assert(s >= 0);
	double oct_const = 2 * (1 + sqrt(2));
	return oct_const * s * s;
}

int main() {
	const char TABLEHEADING[] = "AREAS FOR NORMAL POLYGONS OF GIVEN SIDE LENGTH";
	const char LINEHEADING[] = "SIDE LENGTH: ";
	const char TRIANGLE[] = "Triangle:    ";
	const char SQUARE[] =   "Square:      ";
	const char PENTAGON[] = "Pentagon:    ";
	const char HEXAGON[] =  "Hexagon:     ";
	const char HEPTAGON[] = "Heptagon:    ";
	const char OCTAGON[] =  "Octagon:     ";
	const int STARTVALUE = 1;
	const int FINALVALUE = 6;
	const int STEP = 1;

	cout << TABLEHEADING << endl;
	double a;
	for(int i = STARTVALUE; i < FINALVALUE; i += STEP) {
		cout << LINEHEADING << i << endl;
		a = triangle_area(i);
		cout << TRIANGLE << a << endl;
		a = square_area(i);
		cout << SQUARE << a << endl;
		a = pentagon_area(i);
		cout << PENTAGON << a << endl;
		a = hexagon_area(i);
		cout << HEXAGON << a << endl;
		a = heptagon_area(i);
		cout << HEPTAGON << a << endl;
		a = octagon_area(i);
		cout << OCTAGON << a << endl;
		cout << endl;
	}

	return 0;
}
