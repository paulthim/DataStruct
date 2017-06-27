/*
 * test.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: paul
 */

#include "set.h"
#include <iostream>
#include <cassert>
using namespace std;
using namespace thim_assign_4;

int main()
{
	set s1;
	s1.insert (4);
	s1.insert (5);
	s1.insert (-24);
	s1.insert (89);
	s1.insert (34);
	s1.insert (11);
	s1.insert (0);
	s1.insert (3);
	s1.insert (14);
	s1.insert (28);
	std::cout << s1 << std::endl;
	std::cout << "Set 1 complete" << std::endl;
	std::cout << std::endl;

	set s2;
	s2.insert (6);
	s2.insert (-5);
	s2.insert (-24);
	s2.insert (-89);
	s2.insert (34);
	s2.insert (-11);
	s2.insert (0);
	s2.insert (3);
	std::cout << s2 << std::endl;
	std::cout << "Set 2 complete" << std::endl;
	std::cout << std::endl;

	set s3 = set_union (s1, s2);
	assert (s3.contains (4));
	assert (s3.contains (0));
	assert (s3.contains (-5));
	std::cout << s3 << std::endl;
}


