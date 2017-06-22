#include "complex.h"
#include <cmath>
#include <cassert>

complex::complex (double r, double i)
{
  real_part = r;
  imag_part = i;
}

double complex::get_real_part () const
{
  return real_part;
}

double complex::get_imag_part () const
{
  return imag_part;
}

complex complex::conjugate() const
{
  return complex (real_part, -imag_part);
}

double complex::modulus() const
{
  return sqrt (real_part * real_part + imag_part * imag_part);
}


complex operator + (const complex& c1, const complex& c2)
{
  double r = c1.get_real_part() + c2.get_real_part();
  double i = c1.get_imag_part() + c2.get_imag_part();
  return complex (r,i);
}

complex operator - (const complex& c1, const complex& c2)
{
  double r = c1.get_real_part() - c2.get_real_part();
  double i = c1.get_imag_part() - c2.get_imag_part();
  return complex (r,i);
}

complex operator * (const complex& c1, const complex& c2)
{
  double r = c1.get_real_part() * c2.get_real_part() -
    c1.get_imag_part() * c2.get_imag_part();
  double i = c1.get_imag_part() * c2.get_real_part() +
    c1.get_real_part() * c2.get_imag_part();
  return complex (r,i);
}

complex operator / (const complex& c1, const complex& c2)
{
  assert (c1.get_real_part() != 0 || c1.get_imag_part() != 0);
  double r = c1.get_real_part() * c2.get_real_part() +
    c1.get_imag_part() * c2.get_imag_part();
  double i = c1.get_imag_part() * c2.get_real_part() -
    c1.get_real_part() * c2.get_imag_part();
  double denom = c2.get_real_part() * c2.get_real_part() +
    c2.get_imag_part() * c2.get_imag_part();
  return complex (r/denom,i/denom);
}

bool operator == (const complex& c1, const complex& c2)
{
  return c1.get_real_part() == c2.get_real_part() &&
    c1.get_imag_part() == c2.get_imag_part();
}
