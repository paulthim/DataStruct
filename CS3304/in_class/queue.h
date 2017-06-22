/*
 * queue.h
 *
 *  Created on: Jun 22, 2017
 *      Author: pthim
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <cstdlib>
using namespace std;

namespace main_savitch_8B
{
	template <class Item>
	class queue
	{
	public:
		typedef size_t size_type;
		typedef Item value_type;
		static const size_type CAPACITY = 30;
		queue();
		void push(const Item& entry);
		void pop();
		bool empty() const;
		Item front() const;
	private:
		Item data[CAPACITY];
	};
}

#endif /* QUEUE_H_ */
