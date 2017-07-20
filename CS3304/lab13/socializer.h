/*
 * socializer.h
 *
 *  Created on: Jul 20, 2017
 *      Author: pthim
 */

#ifndef SOCIALIZER_H_
#define SOCIALIZER_H_

#include "graph.h"
#include <set>
#include <string>

using namespace std;

namespace lab_13
{
	class socializer
	{
	public:
			graph<string>* network;
			// CONSTRUCTOR
			socializer() {
				network = new graph<string>();
			}
			socializer(const string& file_name);
			// MODIFICATION MEMBER FUNCTIONS
			void add_friend (const string& my_name, const string& new_friend);
			void remove_friend (const string& my_name, const string& ex_friend);
			// CONST MEMBER FUNCTIONS
			std::set<string> friends(const string& name);
			std::set<string> common_friends (const string& name1, const string& name2);
			std::set<string> friends_of_friends (const string& my_name);
			bool is_friend (const string& my_name, const string& maybe_friend);
	private:
			graph<string>* create_graph (const string& file_name);
			void tokenize (const string& s, string& first, string& second);
			size_t get_index (const graph<string>& g, const string& target);
	};
}

#endif /* SOCIALIZER_H_ */
