/*
 * main.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Paul R Thim
 */
#include "node1.h"
#include <iostream>
#include <cassert>
using namespace main_savitch_5;
using namespace std;

node* merge(node* h1, node* h2) {
	node *h, *t, *c;
	list_copy(h1, h, t);
	c = h;
	if (h2->data() < c->data()) {
		list_head_insert(c, h2->data());
		h2 = h2->link();
	}
	while (h2 != NULL) {
		if (c == h) {
			if(h2->data() < c->data()) {
				list_head_insert(c, h2->data());
				h2 = h2->link();
			}
		}
		if (h2->data() == c->data()) {
			h2 = h2->link();
		}
		if (h2->data() < c->link()->data()) {
			list_insert(c, h2->data());
			h2 = h2->link();
		} else if (c->link() == t) {
			list_insert(c->link(), h2->data());
			h2 = h2->link();
		}
		c = c->link();
	}
	return h;
}

int main() {
	node *head_ptr;
	node *h1, *t1;
	node *h2, *t2;
	node *l;
	cout << "Initialized two empty linked lists." << endl;
	cout << "No populating in both lists independently." << endl;
	cout << "Some values will be the same." << endl;
	h1 = new node(1, NULL);
	h2 = new node(1, NULL);
	l = h1;
	for (int i = 1; i < 7; i++) {
		list_insert(l, i * 7);
		l = l->link();
	}
	t1 = l;
	assert(l->link() == NULL);

	l = h2;
	for (int i = 2; i < 8; i++) {
		list_insert(l, i * i);
		l = l->link();
	}
	t2 = l;
	cout << endl;
	assert(l->link() == NULL);

	cout << "Contents of list 1: ";
	l = h1;
	while (l != NULL) {
		cout << l->data() << " ";
		l = l->link();
	}
	cout << endl;

	cout << "Contents of list 2: ";
	l = h2;
	while (l != NULL) {
		cout << l->data() << " ";
		l = l->link();
	}
	cout << endl;

	cout << "Merging linked lists." << endl;
	head_ptr = merge(h1, h2);
	cout << "Contents of merged list: ";
	l = head_ptr;
	while (l != NULL) {
		cout << l->data() << " ";
		l = l->link();
	}
	cout << endl;
}
