/*
 * Lab 11 - Radix sort
 *
 *  Created on: Jul 18, 2017
 *      Author: Paul Thim
 */

#include <list>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

void radix_sort(list<unsigned int>& l);
void build_unsorted_list(list<unsigned int>& l, size_t i);
bool verify_list(list<unsigned int>& l);
void print_list(list<unsigned int>& l);

const int MAX_ITERATIONS = sizeof(unsigned int)*8;

int main() {
	size_t size, i;
	cout << "How many integers to add?";
	cin >> size;
	list<unsigned int> l, shuffled_l;
	cout << "Generating an unsorted array of unsigned integers of size "
			<< size << ": ";
	build_unsorted_list(l, size);
	assert(l.size() == size);
	cout << "Done.\n";
	//print_list(l);
	cout << "Sorting array: ";
	radix_sort(l);
	assert(verify_list(l));
	cout << "Done.\n";
	assert(l.size() == size);
	assert(l.front() == 0);
	assert(l.back() == pow(size-1, 4));
	//print_list(l);
	return 0;
}

void radix_sort(list<unsigned int>& l_original) {
	list<unsigned int> list0, list1;
	unsigned int i, n, divisor;
	i = 0;
	divisor = 1;
	while (i < MAX_ITERATIONS && i < pow(l_original.size(), 4)) {
		while(!l_original.empty()) {
			n = l_original.front();
			if ((n / divisor) % 2 == 0)
				list0.push_back(n);
			else
				list1.push_back(n);
			l_original.pop_front();
		}
		l_original.splice(l_original.begin(), list1);
		l_original.splice(l_original.begin(), list0);
		divisor = 2 * divisor;
		i++;
	}
}

void build_unsorted_list(list<unsigned int>& l, size_t size) {
	size_t i;
	unsigned int n;
	bool pos = true;
	for (i = 0; i < size; i++) {
		if (pos)
			l.push_back(pow(i, 4));
		else
			l.push_front(pow(i, 4));
		pos = !pos;
	}
}

bool verify_list(list<unsigned int>& l) {
	unsigned int n;
	list<unsigned int>::iterator it = l.begin();
	n = *it;
	it++;
	while (it != l.end()) {
		if (n >= *it)
			return false;
		else {
			n = *it;
			it++;
		}
	}
	return true;
}

void print_list(list<unsigned int>& l) {
	cout << "Array contents:\n";
	for(list<unsigned int>::iterator it = l.begin(); it != l.end(); it++)
		cout << ' ' << *it << '\n';
}
