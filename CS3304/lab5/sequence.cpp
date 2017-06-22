/*
 * sequence.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: Paul Thim
 */

#include "sequence3.h"
#include "node1.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

namespace main_savitch_5
{
	sequence::sequence() {
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0;
	}

	sequence::sequence(const sequence& source) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		//Follow through the source sequence until you encounter the source's cursor

		node* source_ptr;
		source_ptr = source.head_ptr;
		cursor = head_ptr;
		while(source_ptr != source.cursor) {
			precursor = cursor;
			source_ptr = source_ptr->link();
			cursor = precursor->link();
		}
	}

	sequence::~sequence() {
		list_clear(head_ptr);
		many_nodes = 0;
	}

	void sequence::start() {
		cursor = head_ptr;
		precursor = NULL;
	}

	void sequence::advance() {
		if(is_item())
		{
			precursor = cursor;
			node* current_ptr = cursor;
			if(current_ptr == tail_ptr)
				cursor = NULL;
			else
				cursor = current_ptr->link();
		}
	}

	void sequence::insert(const value_type& entry) {
		if(is_item())
		{
			node* insert_ptr;
			if(cursor == head_ptr)
			{
				insert_ptr = head_ptr;
				list_head_insert(insert_ptr, entry);
				cursor = insert_ptr;
				head_ptr = insert_ptr;
			}
			else
			{
				insert_ptr = precursor;
				list_insert(insert_ptr, entry);
				cursor = insert_ptr->link();
			}
		}
		else
		{
			node *ptr = head_ptr;
			list_head_insert(ptr, entry);
			cursor = ptr;
			head_ptr = ptr;
			if(many_nodes == 0)
				tail_ptr = ptr;
		}
		++many_nodes;
	}

	void sequence::attach(const value_type& entry) {
		node *current_ptr;
		if(is_item())
		{
			current_ptr = cursor;
			node* attach_ptr = new node(entry);
			if(current_ptr->link() == NULL)
				tail_ptr = attach_ptr;
			else
				attach_ptr->set_link(current_ptr->link());
			current_ptr->set_link(attach_ptr);
			cursor = current_ptr->link();
			precursor = current_ptr;
		}
		else
		{
			//if no current node, new node is attached at end.
			//if no nodes at all, insert.
			if(many_nodes > 0)
			{
				current_ptr = tail_ptr;
				precursor = tail_ptr;
				list_insert(current_ptr, entry);
				current_ptr = current_ptr->link();
			}
			else
			{
				current_ptr = new node(entry);
				head_ptr = current_ptr;
			}
			tail_ptr = current_ptr;
			cursor = current_ptr;
		}
		++many_nodes;
	}

	void sequence::operator =(const sequence& source) {
		if (head_ptr == source.head_ptr) return;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		node* source_ptr;
		source_ptr = source.head_ptr;
		cursor = head_ptr;
		while(source_ptr != source.cursor) {
			precursor = cursor;
			source_ptr = source_ptr->link();
			cursor = precursor->link();
		}
	}

	void sequence::remove_current() {
		if(is_item()) {
			node* remove_ptr;
			if(cursor == head_ptr){

				remove_ptr = cursor;
				if(many_nodes > 1)
				{
					list_head_remove(remove_ptr);
					head_ptr = remove_ptr;
					cursor = head_ptr;
					precursor = NULL;
				}
				else
				{
					delete head_ptr;
					head_ptr = NULL;
					cursor = NULL;
					precursor = NULL;
				}
			}
			else
			{
				remove_ptr = precursor;
				list_remove(remove_ptr);
				cursor = remove_ptr->link();
			}
			many_nodes--;
		}
	}

	sequence::value_type sequence::current() const {
		assert(is_item());
		node* current_ptr = cursor;
		return current_ptr->data();
	}
}
