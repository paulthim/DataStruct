/*
 *  Created on: Jun 29, 2017
 *      Author: pthim
 *
 *	Lab 8: Exercise 8 from Chapter 10
 *	Function takes a binary search tree as input and produces a linked list of
 *	the entries, with entries sorted.
 */

#include "bintree.h"
#include <list>
#include <iostream>
#include <ctime>
using namespace std;
using namespace main_savitch_10;

binary_tree_node<int>* build_tree();
void print_tree(binary_tree_node<int>* t, int degree);
void add_node(binary_tree_node<int>* root, int n);
void build_list(const binary_tree_node<int>* root, list<int>* l);

int main() {
	binary_tree_node<int>* t;
	list<int>* l;

	t = build_tree();
	print_tree(t, 0);

	l = new list<int>();
	build_list(t, l);
	// I tried calling inorder(l->push_back, t), but couldn't get past a
	// 'reference to non-static member function must be called' error
	for (list<int>::iterator it = l->begin(); it != l->end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}

binary_tree_node<int>* build_tree() {
	// Generates a randomized binary search tree.
	// Returns a pointer to the root node.
	int n, i;
	binary_tree_node<int>* root;
	srand(time(NULL)); // for extra randomness
	n = rand() % 50 + 1;
	root = new binary_tree_node<int>(n);
	for (i = 0; i < 25; i++) {
		n = rand() % 50 + 1;
		add_node(root, n);
	}
	return root;
}

void print_tree(binary_tree_node<int>* t, int degree) {
	// Prefer an in-order printing, rather than the backwards print provided by
	// bintree.h
	if (t == NULL)
		return;
	else {
		cout << setw(degree*2) << "";
		cout << t->data() << endl;
		print_tree(t->left(), degree + 1);
		print_tree(t->right(), degree + 1);
	}
}

void add_node(binary_tree_node<int>* root, int n) {
	if (n == root->data())
		// Disregard duplicate entries, purely preference here.
		return;
	else if (n < root->data()) {
		// If n is smaller, check if a left child exists
		if (root->left() != NULL)
			// If so, continue down the left branch.
			add_node(root->left(), n);
		else {
			// Otherwise, add n as left child.
			root->set_left(new binary_tree_node<int>(n));
			return;
		}
	}
	else if (n > root->data()) {
		//Same as left iterator, but runs if n is larger.
		if (root->right() != NULL)
			add_node(root->right(), n);
		else {
			root->set_right(new binary_tree_node<int>(n));
			return;
		}
	}
}

void build_list(const binary_tree_node<int>* root, list<int>* l) {
	// Copied almost verbatim from the bintree.h inorder function.
	if (root != NULL) {
		build_list(root->left(), l);
		l->push_back(root->data());
		build_list(root->right(), l);
	}
}
