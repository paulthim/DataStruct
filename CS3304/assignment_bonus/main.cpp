/*
 * main.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: paul
 */

#include "set.h"
#include <iostream>
#include <cstdlib>


using namespace std;
using namespace main_savitch_11;

int main() {
	set<int>* s = new set<int>();
	s->print(0);
	size_t i = s->count(0);
	cout << i << endl;
	delete s;
}

