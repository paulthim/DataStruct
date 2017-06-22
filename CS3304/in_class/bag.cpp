#include "bag.h"
#include <cassert>

typedef size_t bag::size_type;


int bag::index_of(int target) const
{
	for (int i = 0; i < count; i++)
	{
		if(items[i] == target) return i;
	}
	return -1;
}

void bag::insert(int new_entry)
{
	//PRECONDITION: Count is less than capacity, and new_entry is an integer.
	//POSTCONDITION: A new copy of new_entry has been added to items.
	assert(count < CAPACITY);
	items[count] = new_entry;
	count++;
}

void bag::remove(int target)
{
	//POSTCONDITION: If the target was in the bag, one copy has been removed. Otherwise, bag is unchanged.
	//Check if target exists in items.
	int i = index_of(target);
	assert(i >= 0);
	items[i] = items[count-1];
	count--;
}

size_t bag::size() const
{
	//POSTCONDITION: return values is the number of integers in bag.
	return count;
}
