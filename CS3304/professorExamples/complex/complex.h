#ifndef _COMPLEX_H
#define _COMPLEX_H

class complex
{
public:
  complex (double r, double i);
  // postcondition: complex number with specified real & imaginary parts has
  //                been created
  double get_real_part () const;
  // postcondition: real part has been returned
  double get_imag_part () const;
  // postcondition: imaginary part has been returned
  complex conjugate() const;
  // postcondition: conjugate has been returned
  double modulus() const;
  // postcondition: modulus has been returned
private:
  double real_part;
  double imag_part;
};

complex operator + (const complex& c1, const complex& c2);
// postcondition: sum of c1 & c2 has been returned

complex operator - (const complex& c1, const complex& c2);
// postcondition: difference of c1 & c2 has been returned

complex operator * (const complex& c1, const complex& c2);
// postcondition: product of c1 & c2 has been returned

complex operator / (const complex& c1, const complex& c2);
// precondition: c2 is not zero
// postcondition: quotient of c1 & c2 has been returned

bool operator == (const complex& c1, const complex& c2);
// postcondition: whether c1 & c2 are equal has been returned
#endif
