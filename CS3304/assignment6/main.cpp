/*
 * main.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: pthim
 */

#include "deque.h"
#include <iostream>
#include <cassert>

int main() {
	std::cout << "Will create two blank deques." << std::endl;
	deque<int>* di;
	std::cout << "Created a blank deque and performing a few basic tasks: ";
	deque<int>* di_empty;
	int i;
	int a[] = {8,7,6,21,28,35,42,49,56,63};
	int b[] = {0,1,4,9,16,25,36,49,64,81};
	di->push_front(7);
	di->push_back(6);
	di->push_front(8);
	for (i = 3; i < 10; i++)
		di->push_back(i * 7);
	assert(di->back() == a[9] && di->front() == a[0]);
	std::cout << "PASSED." << std::endl;

	std::cout << "Will now create a new deque using default copy constructor and passing original deque as parameter: ";
	deque<int>* di2(di);
	assert(di2->back() == a[9] && di2->front() == a[0]);
	std::cout << "PASSED." << std::endl;
	std::cout << "Updating the new deque using pop_back: ";
	di2->pop_back();
	assert(di2->back() == a[8]);
	std::cout << "PASSED." << std::endl;
	std::cout << "Verifying original is unchanged: ";
	assert(di->back() == a[9]);
	std::cout << "PASSED." << std::endl;

	std::cout << "Will now use default assignment operator to assign empty deque to original deque: ";
	di = di_empty;
	assert(di->empty());
	std::cout << "PASSED." << std::endl;
	std::cout << "Will now fill deque using push_back: ";
	for (i = 0; i < 10; i++)
		di->push_back(i * i);
	assert(di->front() == b[0] && di->back() == b[9]);
	std::cout << "PASSED." << std::endl;
	std::cout << "Removing two items using pop_front: ";
	di->pop_front();
	di->pop_front();
	assert(di->front() == b[2]);
	std::cout << "PASSED." << std::endl;

	std::cout << "Creating a deque of doubles to verify template: ";
	deque<double> dd;
	assert(dd.empty());
	std::cout << "PASSED." << std::endl;
	std::cout << "Will now fill deque using push_front: ";
	for (i = 0; i < 10; i++)
		dd.push_back(i / 13);
	std::cout << "PASSED." << std::endl;
	return 0;
}
