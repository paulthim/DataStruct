/*
 * sequence_test.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: pthim
 */

#include "sequence3.h"
#include <iostream>
using namespace main_savitch_5;
using namespace std;

void print(sequence& source) {
	cout << "Sequence is: " << endl;
	source.start();
	while(source.is_item())
		{
			cout << source.current() << " ";
			source.advance();
		}
	cout << endl;
}

int main()
{
	cout << "EVALUATING TEST 5" << endl;
	const size_t TESTSIZE = 30;
	sequence original; // A sequence that we'll copy.
	double items[2*TESTSIZE];
	size_t i;

	for (i = 1; i <= 2*TESTSIZE; i++)
		items[i-1] = i;
	//print(original);

	// Test copying of an empty sequence. After the copying, we change original.
	cout << "Assignment operator test: for an empty sequence." << endl;
	sequence copy1;
	copy1 = original;
	original.attach(1); // Changes the original sequence, but not the copy.

	cout << "Assignment operator test: cursor at tail." << endl;
	for (i=2; i <= 2*TESTSIZE; i++)
		original.attach(i);
	sequence copy2;
	copy2 = original;
	original.remove_current( ); // Delete tail from original, but not the copy
	original.start( );
	original.advance( );
	original.remove_current( ); // Delete 2 from original, but not the copy.
	cout << "Original cursor: " << original.current() << endl;
	cout << "Copy cursor: " << copy2.current() << endl;
	print(original);
	print(copy2);
}


