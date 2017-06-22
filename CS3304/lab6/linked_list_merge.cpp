/*
 * linked_list_merge.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: paul
 */
#include "../lab5/node1.h"
using namespace main_savitch_5;
using namespace std;

node merge_list(const node& head_ptr1, const node& head_ptr2) {
	node* head_ptr;
	node* current_ptr;

	node::value_type entry;
	if (head_ptr1 != NULL && head_ptr2 != NULL) {
		if (head_ptr1.data() < head_ptr2.data()) {
			head_ptr = new node(head_ptr1);
			head_ptr1 = head_ptr1.link();
		}
		else {
			head_ptr = new node(head_ptr2);
			head_ptr2 = head_ptr2.link();
		}
	}
	current_ptr = head_ptr;
	while (head_ptr1 != NULL) {
		if (head_ptr2 != NULL) {
			if (head_ptr1.data() >= head_ptr2.data()) {
				list_insert(current_ptr, head_ptr2.data());
				head_ptr2 = head_ptr2.link();
				if (head_ptr1.data() == head_ptr2.data())
					head_ptr1 = head_ptr1.link();
			}
		} else {
			list_insert(current_ptr, head_ptr1.data());
			head_ptr1 = head_ptr1.link();
		}
		current_ptr = current_ptr->link();
	}
	while (head_ptr2 != NULL) { // If head_ptr1 terminates before head_ptr2
		list_insert(current_ptr, head_ptr2.data());
		head_ptr2 = head_ptr2.link();
	}
	return head_ptr;
}

int main() {
	node* head_ptr1;
	node* head_ptr2;
	node* link_ptr;
	cout << "Initialized two empty linked lists." << endl;
	cout << "No populating in both lists independently." << endl;
	cout << "Some values will be the same." << endl;
	list_head_insert(head_ptr1, 1);
	list_head_insert(head_ptr2, 0);
	link_ptr = head_ptr1;
	for (int i = 1; i < 7; i++) {
		list_insert(link_ptr, i * 7);
		link_ptr = link_ptr->link();
	}
	link_ptr = head_ptr2;
	for (int i = 0; i < 7; i++) {
		list_insert(link_ptr, i * i);
		link_ptr = link_ptr->link();
	}
	cout << endl;
	cout << "Contents of list 1: ";
	link_ptr = head_ptr1;
	while (link_ptr != NULL) {
		cout << link_ptr->data() < " ";
		link_ptr = link_ptr->link();
	}
	cout << endl;
	cout << "Contents of list 2: ";
	link_ptr = head_ptr2;
	while (link_ptr != NULL) {
		cout << link_ptr->data() < " ";
		link_ptr = link_ptr->link();
	}
	cout << endl;
}
