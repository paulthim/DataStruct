#include <iostream>
#include "complex.h"

namespace thim_complex_1A
{
	complex::complex(double initial_a, double initial_b) {
		a = initial_a;
		b = initial_b;
	}

	complex::complex(const complex& source) {
		a = source.get_a();
		b = source.get_b();
	}

	void complex::operator =(const complex& source) {
			a = source.get_a();
			b = source.get_b();
		}

	const complex complex::conjugate() const {
		double new_a;
		double new_b;

		new_a = a;
		new_b = -b;

		complex con(new_a, new_b);
		return con;
	}

	std::ostream& operator <<(std::ostream& outs, const complex& source_num) {
		outs << source_num.get_a() << "+" << source_num.get_b() << "i";
		return outs;
	}

	std::istream& operator >>(std::istream& ins, complex& target_num) {
		ins >> target_num.a >> target_num.b;
		return ins;
	}

	complex operator +(const complex& num1, const complex& num2) {
		double new_a;
		double new_b;

		new_a = num1.get_a() + num2.get_a();
		new_b = num1.get_b() + num2.get_b();

		complex sum(new_a, new_b);
		return sum;
	}

	complex operator -(const complex& num1, const complex& num2) {
		double new_a;
		double new_b;

		new_a = num1.get_a() - num2.get_a();
		new_b = num1.get_b() - num2.get_b();

		complex diff(new_a, new_b);
		return diff;
	}

	complex operator *(const complex& num1, const complex& num2) {
		//Cross-wise multiplication:
		//(a + bi)(x + yi) = (ax - by) + (ay + bx)i
		double new_a = (num1.get_a() * num2.get_a()) - (num1.get_b() * num2.get_b());
		double new_b = (num1.get_a() * num2.get_b()) + (num1.get_b() * num2.get_a());

		complex total(new_a, new_b);
		return total;
	}

	complex operator /(const complex& num1, const complex& num2) {
		//Division:
		//(a + bi)/(c + di) * (c - di)/(c - di) = (a + bi)(c - di)/(c^2 + d^2)
		complex numerator(num2.conjugate() * num1);
		double denom, new_a, new_b;

		denom = num2.get_a() * num2.get_a() +  num2.get_b() * num2.get_b();

		new_a = numerator.get_a() / denom;
		new_b = numerator.get_b() / denom;

		complex result(new_a, new_b);
		return result;
	}
}
