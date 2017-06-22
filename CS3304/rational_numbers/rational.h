#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class rational
{
public:
  rational (int n = 0, int d = 1);
  // precondition: d is not zero
  // postcondition: rational number has been create with numerator n & denominator d
  double get_num() const;
  // postcondition: numerator has been returned
  double get_denom () const;
  // postcondition: denominator has been returned
private:
  void reduce();
  // postcondition: rational number is represented in lowest terms with a positive
    //                   denominator
  int num;
  int denom;
};

rational operator + (const rational& r1, const rational& r2);
// postcondition: sum of r1 & r2 has been returned

rational operator - (const rational& r1, const rational& r2);
// postcondition: difference of r1 & r2 has been returned

rational operator * (const rational& r1, const rational& r2);
// postcondition: product of r1 & r2 has been returned

rational operator / (const rational& r1, const rational& r2);
// precondition: r2 is not zero
// postcondition: quotient of r1 & r2 has been returned

bool operator == (const rational& r1, const rational& r2);
// postcondition: whether  r1 & r2 are equal has been returned

bool operator != (const rational& r1, const rational& r2);
// postcondition: whether r1 & r2 are not equal has been returned

bool operator <= (const rational& r1, const rational& r2);
// postcondition: whether r1 is less than or equal to r2 has been returned

bool operator >= (const rational& r1, const rational& r2);
// postcondition: whether r1 is greater than or equal to r2 has been returned

bool operator < (const rational& r1, const rational& r2);
// postcondition: whether  r1 is less than r2 has been returned

bool operator > (const rational& r1, const rational& r2);
// postcondition: whether r1 is greater than  r2 has been returned

std::ostream& operator << (std::ostream& output, const rational& r);
// postcondition: r has been displayed on output
#endif
