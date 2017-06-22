#include "rational.h"
#include <cassert>
#include <iostream>

int main ()
{
  rational r;
  assert (r.get_num() == 0);
  assert (r.get_denom() == 1);

  rational r1 (6, -4);
  assert (r1.get_num() == -3);
  assert (r1.get_denom() == 2);

  rational r2 (-8, -2);
  assert (r2.get_num() == 4);
  assert (r2.get_denom() == 1);

  rational r3 = r1 + r2;
  assert (r3.get_num() == 5);
  assert (r3.get_denom() == 2);

  rational r4 = r1 - r2;
  assert (r4.get_num() == -11);
  assert (r4.get_denom() == 2);

  rational r5 = r1 * r2;
  assert (r5.get_num() == -6);
  assert (r5.get_denom() == 1);

  rational r6 = r1 / r2;
  assert (r6.get_num() == -3);
  assert (r6.get_denom() == 8);

  assert ((r1 == r2) == false);
  assert ((r1 != r2) == true);
  assert ((r1 < r2) == true);
  assert ((r1 <= r2) == true);
  assert ((r1 > r2) == false);
  assert ((r1 >= r2) == false);

  std::cout << r1 << std::endl;

  return 0;
}
