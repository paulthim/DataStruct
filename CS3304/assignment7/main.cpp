/*
 * main.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: Paul Thim
 */

#include "bintree.h"
#include <list>
#include <cstdlib>

using namespace std;
using namespace main_savitch_10;

binary_tree_node<int>* node_from_list(const list<int>* l, int first, int last);
list<int>* create_sorted_list();
void print_tree(binary_tree_node<int>* t, int degree);

int main() {
	list<int>* l = create_sorted_list();
	binary_tree_node<int>* root;
	root = node_from_list(l, 0, l->size()-1);
	print_tree(root, 0);
	delete l;
	delete root;
	return 0;
}

binary_tree_node<int>* node_from_list(const list<int>* l, int first, int last) {
	if (first > last)
		return NULL;
	binary_tree_node<int>* root_ptr;
	int i, mid;
	mid = (first + last) / 2;
	list<int>::const_iterator iter = l->begin();
	for (i = 0; i < mid; i++) {
		iter++;
	}
	root_ptr = new binary_tree_node<int>(*iter);
	root_ptr->set_left(node_from_list(l, first, mid - 1));
	root_ptr->set_right(node_from_list(l, mid+1, last));
	return root_ptr;
}

list<int>* create_sorted_list() {
	list<int>* l = new list<int>;
	int i;
	for (i = 0; i < 15; i++)
		l->push_back(i);
	return l;
}

void print_tree(binary_tree_node<int>* t, int degree) {
	if (t == NULL)
		return;
	else {
		cout << setw(degree*2) << "";
		cout << t->data() << endl;
		print_tree(t->left(), degree + 1);
		print_tree(t->right(), degree + 1);
	}
}
