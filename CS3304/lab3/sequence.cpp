#include "sequence1.h"
#include <cassert>
#include <cstdlib>
using namespace main_savitch_3;

const sequence::size_type sequence::CAPACITY;

sequence::sequence() {
	used = 0;
	current_index = 0;
}

void sequence::start() {
	current_index = 0;
}

void sequence::advance() {
	if(is_item()) {
		current_index++;
	}
}

void sequence::insert(const value_type& entry) {
	assert(sequence::size() < CAPACITY);
	//if (!is_item()), we are either at the end or have an empty sequence. 
	//	Either way, start(), set data[current_index] = entry
	//increment count
	if(sequence::size() == 0) {
		data[current_index] = entry;
		used++;
	} else {
		if (!is_item()) {
			start();
		}
		size_type insert_index = current_index;
		value_type entry_item = entry;
		while(is_item()) {
			value_type v = current();
			data[current_index] = entry_item;
			entry_item = v;
			advance();
		}
		data[current_index] = entry_item;
		current_index = insert_index;
		used++;
	}
}

void sequence::attach(const value_type& entry) {
	assert(size() < CAPACITY);
	if(is_item()) {
		//Back to basics, stop trying to optimize, just make it work.
		//if current_index+1 < capacity, advance and check if that is an item.
		//if it is, pop it to a holder variable, insert entry. 
		//Assign the item in holder variable to entry, repeat.
		value_type entry_holder = entry;
		size_type index_holder = 0;
		index_holder = current_index+1;
		while (current_index+1 < size()) {
			advance();
			value_type place_holder = current();
			data[current_index] = entry_holder;
			entry_holder = place_holder;
		}
		advance();
		data[current_index] = entry_holder;
		current_index = index_holder;
		used++;
	}
	else {
		//either at the end of sequence or have an empty sequence. Either way:
		data[current_index] = entry;
		used++;
	}
}

void sequence::remove_current() {
	assert(is_item());
	//Delete the current item.
	//if there is a next item, set it at current_index and proceed until we reach the end of the list.
	//if there is no next item, decrement count, leave current_index as is.
	//Regardless, current_index should remain in the same place.
	size_type remove_index = current_index; // use placeholder remove_index to allow me to use advance() and current() methods.
	advance();
	while(is_item()) {
		data[current_index - 1] = current();
		advance();
	}
	current_index = remove_index;
	used--;
}

sequence::size_type sequence::size() const {
	return used;
}

bool sequence::is_item() const {
	return current_index < used;
}

sequence::value_type sequence::current() const {
	assert(is_item());
	return data[current_index];
}
