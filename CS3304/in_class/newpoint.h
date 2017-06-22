#ifndef MAIN_SAVITCH_NEWPOINT_H
#define MAIN_SAVITCH_NEWPOINT_H
#include <iostream>

namespace main_savitch_2B
{
	class point {
	public:
		//CONSTRUCTOR
		point(double initial_x = 0.0, double initial_y = 0.0);
		//MODIFICATION MEMBER FUNCTIONS
		void shift(double x_amount, double y_amount);
		void rotate90();
		//CONSTANT MEMBER FUNCTIONS
		double get_x() const { return x; }
		double get_y() const { return y; }
		//FRIEND FUNCTION
		friend std::istream& operator >>(std::istream& inst, point& target); //Only friends can access your private parts
	private:
		double x, y;
	};

	//NONMEMBER FUNCTIONS for point class
	double distance(const point& p1, const point& p2);
	point middle(const point& p1, const point& p2);
	point operator +(const point& p1, const point& p2);
	bool operator ==(const point& p1, const point& p2);
	bool operator !=(const point& p1, const point& p2);
	std::ostream& operator <<(std::ostream & outs, const point& source);
}

#endif
