#include <iostream>
#include <cmath>
#include "newpoint.h"

namespace main_savitch_2B
{
	point::point(double initial_x, double initial_y) {
		x = initial_x;
		y = initial_y;
	}

	void point::shift(double x_amount, double y_amount) {
		x += x_amount;
		y += y_amount;
	}

	void point::rotate90() {
		double invert_x = -x;

		x = y;
		y = invert_x;
	}

	double distance(const point& p1, const point& p2) {
		double a, b, c_squared;

		a = p1.get_x() - p2.get_x();
		b = p1.get_y() - p2.get_y();

		c_squared = a * a + b * b;
		return sqrt(c_squared);
	}

	bool operator ==(const point& p1, const point& p2) {
		return (p1.get_x() == p2.get_x() && p1.get_y() == p2.get_y());
	}
}
