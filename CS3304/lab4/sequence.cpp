/*
 * sequence.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: pthim
 */

#include <algorithm>
#include <cassert>
#include "sequence2.h"

namespace main_savitch_4
{
	// TYPEDEFS and MEMBER CONSTANTS
	const sequence::size_type sequence::DEFAULT_CAPACITY;

	// CONSTRUCTORS and DESTRUCTORS
	sequence::sequence(size_type initial_capacity) {
		capacity = initial_capacity;
		data = new value_type[initial_capacity];
		used = 0;
		current_index = 0;
	}

	sequence::sequence(const sequence& source) {
		data = new value_type[source.capacity];
		capacity = source.capacity;
		used = source.used;
		std::copy(source.data, source.data + used, data);
		current_index = source.current_index;
	}

	sequence::~sequence( ) {
		delete [] data;
	}

	void sequence::resize(size_type new_capacity) {
		value_type *larger_array;

		if (new_capacity == capacity) return;
		if (new_capacity < used) new_capacity = used;

		larger_array = new value_type[new_capacity];
		std::copy(data, data + used, larger_array);
		delete [] data;
		data = larger_array;
		capacity = new_capacity;
	}

	void sequence::start() {
		current_index = 0;
	}

	void sequence::advance() {
		if(is_item())
			current_index++;
	}

	void sequence::insert(const value_type& entry) {
		if(size() == capacity) {
			resize(capacity*2);
		}
		if(!is_item())
			current_index = 0;
		for(size_type i = used; i > current_index; --i) {
			data[i] = data[i-1];
		}
		data[current_index] = entry;
		++used;
	}

	void sequence::attach(const value_type& entry) {
		if(size() == capacity) {
			resize(capacity*2);
		}
		if(used == 0) {
			current_index = 0;
			data[current_index] = entry;
		}
		else
		{
		if(!is_item())
			current_index = used - 1;
		for(size_type i = used; i > current_index; --i)
			data[i] = data[i-1];
		current_index++;
		data[current_index] = entry;
		}
		used++;
	}

	void sequence::remove_current() {
		assert(is_item());
		for(size_type i = current_index; i < used - 1; ++i) {
			data[i] = data[i+1];
		}
		--used;
	}

	void sequence::operator =(const sequence& source) {
		if(this == &source) return;
		if(source.capacity > capacity) {
			value_type *temp_data;
			temp_data = new value_type[source.capacity];
			delete [] data;
			data = temp_data;
			capacity = source.capacity;
		}

		used = source.used;
		current_index = source.current_index;
		std::copy(source.data, source.data + used, data);
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
}
