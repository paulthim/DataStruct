#ifndef THIM_BAG_H
#define THIM_BAG_H

class bag
{
public:
	//TYPEDEF AND MEMBER CONSTANTS
	typedef int value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 20;

	//DEFAULT CONSTRUCTOR
	bag( ) {count = 0;};

	//MODIFICATION MEMBER FUNCTIONS
	void insert(value_type new_entry);
	void remove(value_type target);

	//CONSTANT MEMBER FUNCTIONS
	size_type size( ) const;
	int index_of(int target) const;

private:
	value_type items[CAPACITY];
	size_type count;
};

#endif /* THIM_BAG_H */
