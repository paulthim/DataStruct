/*
 * set.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: Paul Thim
 */

#include "set.h"

set::set() {
	used = 0;
}

void set::insert(const value_type& entry) {
	if(used == CAPACITY)
		return;
	else if (contains(entry)) {
		return;
	} else {
		int i = 0;
		int n = data[i];
		while(n < entry && i < used) {
			i++;
			n = data[i];
		}
		data[i] = entry;
		int b;
		while (i < used) {
			i++;
			b = data[i];
			data[i] = n;
			n = b;
		}
		used++;
	}
}

void set::remove(const value_type& entry) {
	int i = find(entry);
	if (i == used)
		return;
	while(i < used-1) {
		data[i] = data[i+1];
		i++;
	}
	used--;
}

set::size_type set::size() const {
	return used;
}

bool set::contains(const value_type& entry) const {
	return(find(entry) != used);
}

set set_union (const set& s1, const set& s2) {
	set union_set;
	int a = 0, b = 0, i = 0;
	int max = (s1.used > s2.used ? s1.used : s2.used);
	while (i < max) {
		union_set.insert(s1.data[i]);
		i++;
	}
	i = 0;
	while (i < s2.used) {
		union_set.insert(s2.data[i]);
		i++;
	}
	return union_set;
}

set set_intersection (const set& s1, const set& s2) {
	set intersect_set;
	for (int i = 0; i < s1.used; i++) {
		if (s2.contains(s1.data[i]))
			intersect_set.insert(s1.data[i]);
	}
	return intersect_set;
}

set set_difference (const set& s1, const set& s2) {
	set diff_set;
	for (int i = 0; i < s1.used; i++) {
			if (!s2.contains(s1.data[i]))
				diff_set.insert(s1.data[i]);
		}
	return diff_set;
}

bool is_subset(const set& s1, const set& s2) {
	set subset = set_intersection(s1, s2);
	if (subset.size() == s1.size())
		return true;
	else
		return false;
}

bool operator == (const set& s1, const set& s2) {
	if(s1.size() != s2.size())
		return false;
	else {
		for (int i = 0; i < s1.size(); i++) {
			if(s1.data[i] != s2.data[i])
				return false;
		}
		return true;
	}
}

std::ostream& operator << (std::ostream& output, const set& s) {
	for (int i = 0; i < s.size(); i++)
		output << s.data[i] << " ";
	return output;
}

set::size_type set::find(const value_type& entry) const {
	if(used == 0)
		return used;
	else {
		int i = used/2;
		if(data[i] == entry)
			return i;
		else if(data[i] < entry) {
			while(i < used-1) {
				i++;
				if(data[i] == entry)
					return i;
			}
		}
		else if(data[i] > entry) {
			while(i > 0) {
				i--;
				if(data[i] == entry)
					return i;
			}
		}
	return used;
	}
}


