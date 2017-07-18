/*
 * Lab 12
 *
 *  Created on: Jul 18, 2017
 *      Author: Paul Thim
 */

#include "graph.h"
#include <iostream>
#include <cassert>
#include <set>

using namespace main_savitch_15;
using namespace std;

const string VERTICES[] = {"v0", "v1", "v2", "v3", "v4", "v5"};

int main() {
	cout << "Creating empty graph with max 20 vertices: ";
	graph<string> g;
	assert(g.size() == 0);
	cout << "Done.\n";

	cout << "Adding 6 loose vertices into the graph:";
	for (int i = 0; i < 6; i++)
		g.add_vertex(VERTICES[i]);
	assert(g.size() == 6);
	cout << "Done\n";

	cout << "Adding edges: ";
	g.add_edge(0, 1);
	g.add_edge(1, 3);
	g.add_edge(2, 1);
	g.add_edge(3, 4);
	g.add_edge(4, 1);
	g.add_edge(4, 3);
	assert(g.is_edge(0, 1));
	assert(g.is_edge(3, 4));
	assert(!g.is_edge(4,5));
	cout << "Done.\n";

	cout << "Removing edge: ";
	g.remove_edge(3,4);
	assert(!g.is_edge(3,4));
	assert(g.is_edge(4,3));
	cout << "Done.\n";

	cout << "Adding edges between v5 and three other vertices and calling the"
			<< " neighbors function: ";
	g.add_edge(5, 0);
	g.add_edge(5, 2);
	g.add_edge(5, 4);
	std::set<size_t> neighbors_set = g.neighbors(5);
	assert(neighbors_set.size() == 3);
	cout << "Done.\n";

	cout << "Checking [] override: ";
	assert(g[0] == "v0");
	assert(g[4] == "v4");
	cout << "Done\n";

}
