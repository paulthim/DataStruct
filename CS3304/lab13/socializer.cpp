/*
 * socializer.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: pthim
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include "socializer.h"

using namespace std;

namespace lab_13
{
	socializer::socializer(const string& file_name) {
		network = create_graph(file_name);
	}

	void socializer::add_friend(const string& my_name, const string& new_friend) {
		size_t m, n;
		network->add_vertex(new_friend);
		m = get_index(*network, my_name);
		n = get_index(*network, new_friend);
		network->add_edge(m, n);
	}

	void socializer::remove_friend(const string& my_name, const string& ex_friend) {
		size_t m, n;
		m = get_index(*network, my_name);
		n = get_index(*network, ex_friend);
		network->remove_edge(m, n);
	}

	set<string> socializer::friends(const string& name) {
		size_t n;
		string f_name;
		set<size_t> f_i_set;
		set<string> f_set;
		n = get_index(*network, name);
		f_i_set = network->neighbors(n);
		for (set<size_t>::iterator it = f_i_set.begin(); it != f_i_set.end(); it++) {
			f_set.insert((*network)[*it]);
		}
		return f_set;
	}

	set<string> socializer::common_friends (const string& name1, const string& name2) {
		//TODO: common_friends
		// will implement a set-intersect method
		size_t m, n;
		set<string> f_set;
		set<size_t> f_i_set1;
		set<size_t> f_i_set2;
		m = get_index(*network, name1);
		n = get_index(*network, name2);
		f_i_set1 = network->neighbors(m);
		f_i_set2 = network->neighbors(n);
		for (set<size_t>::iterator it = f_i_set1.begin(); it != f_i_set1.end(); it++) {
			if (f_i_set2.find(*it) != f_i_set2.end())
				f_set.insert((*network)[*it]);
		}
		return f_set;
	}

	set<string> socializer::friends_of_friends (const string& my_name) {
		set<string> f_set;
		set<size_t> f_i_set; //
		set<size_t> f_i_set2;
		set<size_t>::iterator it;
		set<size_t>::iterator it2;
		f_i_set = network->neighbors(get_index(*network, my_name));
		for (it = f_i_set.begin(); it != f_i_set.end(); it++) {
			f_i_set2 = network->neighbors(*it);
			for (it2 = f_i_set2.begin(); it2 != f_i_set2.end(); it2++)
				f_set.insert((*network)[*it2]);
		}
		return f_set;
	}

	bool socializer::is_friend(const string& my_name, const string& maybe_friend) {
		size_t m, f;
		m = get_index(*network, my_name);
		f = get_index(*network, maybe_friend);
		return network->is_edge(m, f);
	}

	void socializer::tokenize (const string& s, string& first, string& second) {
		stringstream ss (s);
		ss >> first;
		ss >> second;
	}

	size_t socializer::get_index (const graph<string>& g, const string& target) {
		size_t i = 0;
		while (i < g.size() && g[i] != target)
			++i;
		assert (i < g.size());
		return i;
	}

	graph<string>* socializer::create_graph (const string& file_name) {
		graph<string>* g = new graph<string>;
		ifstream input(file_name.c_str());
		size_t num;
		input >> num;
		string temp;
		getline (input, temp);
		assert (num <= g -> MAXIMUM);
		string* names = new string[num];
		for (size_t i = 0; i < num; ++i)
		{
			string s;
			getline (input, s);
			names[i] = s;
			g -> add_vertex (s);
		}
		string line;
		while (getline (input, line))
		{
			string first, second;
			tokenize (line, first, second);
			g -> add_edge (get_index (*g, first), get_index (*g, second));
		}
		input.close();
		return g;
	}
}
