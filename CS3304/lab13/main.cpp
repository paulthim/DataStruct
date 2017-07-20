/*
 * main.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: pthim
 */

#include <cassert>
#include <iostream>
#include <set>
#include "socializer.h"

using namespace lab_13;
using namespace std;

int main() {
	set<string>::iterator it;

	socializer s("input.txt");
	assert(s.is_friend("Bob", "Sally"));
	set<string> friends;
	friends = s.friends("Bob");
	for(it = friends.begin(); it != friends.end(); it++)
		cout << *it << ' ';
	cout << '\n';

	friends = s.common_friends("Bob", "Barbara");
	for(it = friends.begin(); it != friends.end(); it++)
		cout << *it << ' ';
	cout << '\n';

	friends = s.friends_of_friends("Barbara");
	for(it = friends.begin(); it != friends.end(); it++)
		cout << *it << ' ';
	cout << '\n';
	return 0;
}
