/*
 * sequence_test2.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: paul
 */

#include <iostream>    // Provides cout.
#include <string.h>      // Provides memcpy.
#include <cstdlib>     // Provides size_t.
#include "sequence2.h" // Provides the Sequence class with double items.
using namespace std;
using namespace main_savitch_4;

int main()
{
	sequence original;
	double items[2*original.DEFAULT_CAPACITY];
	size_t i;

	for (i = 1; i <= 2*original.DEFAULT_CAPACITY; i++)
		items[i-1] = i;

	sequence copy1(original);
	original.attach(1);

	for(i = 2; i <= 2*original.DEFAULT_CAPACITY; i++)
		original.attach(i);
	sequence copy2(original);
	original.start();
	original.advance();
	cout << "Current item for original is: " << original.current() << endl;
	original.remove_current();
	cout << "Current item for original  is: " << original.current() << endl;
	cout << "Current sequence for original : " << endl;
	original.start();
	while(original.is_item()) {
		cout << original.current() << " ";
		original.advance();
	}
	cout << endl;

	cout << "Current item for copy2 is: " << copy2.current() << endl;
}


