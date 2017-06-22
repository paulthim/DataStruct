#ifndef THIM_COMPLEX_H
#define THIM_COMPLEX_H
#include <iostream>

namespace thim_complex_1A
{
	class complex {
	public:
		//CONSTRUCTOR
		complex(double inital_a = 0.0, double initial_b = 0.0);

		//COPY CONSTRUCTOR
		complex(const complex& source);

		void operator =(const complex& num2);

		const complex conjugate() const;

		//CONSTANT MEMBER FUNCTIONS
		double get_a() const { return a; }
		double get_b() const { return b; }

		//FRIEND FUNCTION
		friend std::istream& operator >>(std::istream& ins, complex& target_num);

	private:
		double a, b; //real and imaginary numbers for the complex number
	};

	complex operator +(const complex& num1, const complex& num2);
	complex operator -(const complex& num1, const complex& num2);
	complex operator *(const complex& num1, const complex& num2);
	complex operator /(const complex& num1, const complex& num2);
	std::ostream& operator <<(std::ostream& outs, const complex& source_num);
}

#endif /* COMPLEX_H */
