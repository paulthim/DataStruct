/*
 * main.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: paul
 */
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

void insertionsort(int data[], size_t ss, size_t max);
void fill_array(int data[], size_t max);
void shuffle_array(int data[], size_t max);
void print_array(int data[], size_t size);

int main() {
	size_t size, i;
	size = 226;
	cout << "Generating a sorted array of integers of size " << size << ": ";
	int data[size];
	int shuffled_data[size];
	fill_array(data, size);
	cout << "Done." << endl;

	cout << "Copying original array and shuffling new array: ";
	copy(data, data + size, shuffled_data);
	shuffle_array(shuffled_data, size);
	cout << "Done." << endl;
	//print_array(shuffled_data, size);

	cout << "Performing shell sort: ";
	size_t ss = size / 2;
	while (ss > 0) {
		//cout << "Gap size: " << ss << endl;
		insertionsort(shuffled_data, ss, size);
		//print_array(shuffled_data, size);
		ss = ss / 2.2;
	}
	cout << "Done." << endl;

	cout << "Comparing array post-sort to original, sorted array: ";
	bool same = true;
	for (i = 0; i < size; i++)
		if (data[i] != shuffled_data[i])
			same = false;
	if (same)
		cout << "New array is properly sorted." << endl;
	else
		cout << "New array is not sorted." << endl;
}

void insertionsort(int data[], size_t ss, size_t max) {
	size_t current_i, starting_i;
	int n, j;
	starting_i = 0;
	while (starting_i <= ss - 1) {
		for (current_i = starting_i + ss; current_i < max; current_i += ss) {
			n = data[current_i];
			j = current_i - ss;
			while (j >= 0 && data[j] > n) {
				data[j + ss] = data[j];
				j -= ss;
			}
			data[j + ss] = n;
		}
	starting_i++;
	}
}

void fill_array(int data[], size_t max) {
	size_t i;
	int n;
	n = 0;
	for (i = 0; i < max; i++) {
		data[i] = n;
		n++;
	}
}

void shuffle_array(int data[], size_t max) {
	size_t i, j;
	int n;
	for (i = max - 1; i > 1; i--) {
		j = rand() % i;
		n = data[j];
		data[j] = data[i];
		data[i] = n;
	}
}

void print_array(int data[], size_t size) {
	cout << "Array contents: ";
	for (size_t i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
}
