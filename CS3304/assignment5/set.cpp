/*
 * set.cpp
 *
 *  Created on: Jun 27, 2017
 *      Author: pthim
 */
#include "set.h"
#include "node1.h"

namespace main_savitch_5 {
set::set() {
	head = NULL;
	used = 0;
}

set::set(const set& source) {
	node* tail;
	list_copy(source.head, head, tail);
	used = source.used;
}

set::set& set::operator =(const set& source) {
	if (head == source.head)
		return *this;
	list_clear(head);
	node* tail;
	list_copy(source.head, head, tail);
	used = source.used;
	return *this;
}

void set::insert(const value_type& entry) {
	if (contains(entry))
		return;
	else {
		list_head_insert(head, entry);
		used++;
	}
}

void set::remove(const value_type& entry) {
	if (used == 0)
		return;
	if (head->data() == entry)
		list_head_remove(head);
	else {
		node* ptr = head;
		while (ptr->link() != NULL) {
			if (ptr->link()->data() == entry) {
				list_remove(ptr);
				used--;
				return;
			}
		}
	}
}

set::size_type set::size() const {
	return used;
}

bool set::contains(const value_type& entry) const {
	if (used == 0)
		return false;
	node* ptr;
	ptr = list_search(head, entry);
	if (ptr == NULL)
		return false;
	else
		return true;
}

set::set set_union(const set& s1, const set& s2) {
	set su(s1);
	set::size_type i;
	node* ptr;
	i = s2.used;
	ptr = s2.head;
	while(i > 0) {
		if (!s1.contains(ptr->data()))
			su.insert(ptr->data());
		ptr = ptr->link();
		i++;
	}
	return su;
}

set::set set_intersection(const set& s1, const set& s2) {
	set si;
	set::size_type i;
	node* ptr;
	i = s2.used;
	ptr = s2.head;
	while(i > 0) {
		if (s1.contains(ptr->data()))
			si.insert(ptr->data());
		i++;
	}
	return si;
}

set::set set_difference(const set& s1, const set& s2) {
	set sd(s1);
	node* ptr;
	set::size_type i;
	ptr = sd.head;
	return sd;
}
}
