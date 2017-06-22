#include "rational.h"
#include <cassert>
#include <cmath>

int gcd (int larger, int smaller)
{
  assert (larger > 0 && smaller > 0);
  assert (larger >= smaller);
  int result;
  if (larger % smaller == 0)
    result = smaller;
  else
    result = gcd (smaller, larger % smaller);
  return result;
}

rational::rational (int n, int d)
{
  assert (d != 0);
  num = n;
  denom = d;
  if (denom < 0)
  {
    denom *= -1;
    num *= -1;
  }
  if (num == 0)
    denom = 1;
  else
    reduce();
}

double rational::get_num() const
{
  return num;
}

double rational::get_denom () const
{
  return denom;
}

void rational::reduce()
{
  int common;
  if (std::abs(num) >= denom)
    common = gcd (std::abs(num), denom);
  else
    common = gcd (denom,std::abs(num));
  num /= common;
  denom /= common;
}

rational operator + (const rational& r1, const rational& r2)
{
  int n = r1.get_num() * r2.get_denom() + r1.get_denom() * r2.get_num();
  int d = r1.get_denom() * r2.get_denom();
  return rational (n,d);
}

rational operator - (const rational& r1, const rational& r2)
{
  int n = r1.get_num() * r2.get_denom() - r1.get_denom() * r2.get_num();
  int d = r1.get_denom() * r2.get_denom();
  return rational (n,d);
}

rational operator * (const rational& r1, const rational& r2)
{
  int n = r1.get_num() * r2.get_num();
  int d = r1.get_denom() * r2.get_denom();
  return rational (n,d);
}

rational operator / (const rational& r1, const rational& r2)
{
  assert (r2.get_num() != 0);
  int n = r1.get_num() * r2.get_denom();
  int d = r1.get_denom() * r2.get_num();
  return rational (n,d);
}

bool operator == (const rational& r1, const rational& r2)
{
  return (r1.get_num() == r2.get_num()) && (r1.get_denom() == r2.get_denom());
}

bool operator != (const rational& r1, const rational& r2)
{
  return !(r1 == r2);
}

bool operator <= (const rational& r1, const rational& r2)
{
  return (r1 < r2) || (r1 == r2);
}

bool operator >= (const rational& r1, const rational& r2)
{
  return !(r1 < r2);
}

bool operator < (const rational& r1, const rational& r2)
{
  return r1.get_num() * r2.get_denom() < r1.get_denom() * r2.get_num();
}

bool operator > (const rational& r1, const rational& r2)
{
  return !(r1 <= r2);
}

std::ostream& operator << (std::ostream& output, const rational& r)
{
  output << r.get_num() << "/" << r.get_denom();
  return output;
}
