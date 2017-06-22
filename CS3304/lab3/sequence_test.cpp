#include "sequence1.h"
#include <iostream>
using namespace std;
using namespace main_savitch_3;

int i;

void move_to_position(int index, sequence &s) {
	s.start();
	i = 0;
	while (i < index) {
		s.advance();
		i++;
	}
}
void insert_into_sequence(double entry, sequence &s) {
	cout << "Inserting new item at index " << i << endl;
	s.insert(entry);
	cout << "Current item is " << s.current() << " and sequence size is " << s.size() << endl;
	cout << "Sequence after insert function:";
	s.start();
	while(s.is_item()) {
		cout << s.current() << " ";
		s.advance();
	}
	cout << endl;
}

void attach_into_sequence(double entry, sequence &s) {
	cout << "Attaching item after index " << i << endl;
	s.attach(entry);
	cout << "Current item is " << s.current() << " and sequence size is " << s.size() << endl;
}

void remove_from_sequence(int index, sequence &s) {
	move_to_position(index, s);
	cout << "Removing item " << s.current() << " at index " << i << endl;
	s.remove_current();
	if(s.is_item()) {
		cout << "Current item is " << s.current() << ". ";
	}
	cout << "Sequence size is " << s.size() << endl;
	cout << "Sequence after remove function:";
	s.start();
	while(s.is_item()) {
		cout << s.current() << " ";
		s.advance();
	}
	cout << endl;
}

void print_sequence(sequence &test) {
	test.start();
	cout << "Sequence is: ";
	while (test.is_item()) {
		cout << test.current() << " ";
		test.advance();
	}
	cout << endl;
}

int main() {
	sequence test;
	cout << "Sequence 'test' initialized and empty." << endl;
	test.attach(20);
	test.attach(30);
	print_sequence(test);
	test.advance();
	test.insert(10);
	print_sequence(test);
	test.advance();
	test.advance();
	test.advance();
	//cout << "Current item is: " << test.current() << endl;
	for (int i = 4; i <= test.CAPACITY; i++) {
		test.attach(i*10);
	}
	print_sequence(test);


}
