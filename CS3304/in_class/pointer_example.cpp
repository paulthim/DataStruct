/*
 * pointer_example.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: pthim
 */

#include <iostream>
using namespace std;

int main() {
	int i = 42;
	int *p1;
	int* p2;
	p1 = &i;
	p2 = p1;

	cout << *p1 << endl;
	cout << *p2 << endl;
}


