/*
 * main.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: paul
 */

#include "priority_queue.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
	priority_queue<int>* q = new priority_queue<int>();
	cout << "Created Priority queue." << endl;
	q->push(5);
	q->push(7);
	assert(q->size() == 2);
	assert(q->top() == 7);
	q->pop();
	assert(q->top() == 5);
	return 0;
}
