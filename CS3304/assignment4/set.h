#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
  typedef int value_type;
  typedef std::size_t size_type;
  static const size_type DEFAULT_CAPACITY = 30;

  set(size_type initial_capacity = DEFAULT_CAPACITY);
  // postcondition: empty set has been created
  // O(1)
  
  set(const set& source);

  ~set();

  void resize(size_type new_capacity);
  // postcondition: the set's capacity is changed to new_capacity (but not less
  // than the number of items already contained.

  void insert (const value_type& entry);
  // precondition: if entry is not in the set, set is not full
  // postcondition: entry is in the set
  // O(O(contains()) + 273) = O(305)

  void remove (const value_type& entry);
  // postcondition: entry is not in the set
  // O(O(find() + 89) = O(120)

  size_type size() const;
  // postcondition: number of elements in the set has been returned
  // O(1)

  bool contains (const value_type& entry) const;
  // postcondition: whether entry is in the set has been returned
  // O(32)

  friend set set_union (const set& s1, const set& s2);
  //postcondition: union of s1 & s2 has been returned
  // O(7 + 80 * (insert() + 1)) = O(24408)

  friend set set_intersection (const set& s1, const set& s2);
  // postcondition: intersection of s1 & s2 has been returned
  // O(1 + 30 * contains() * insert()) = O(292801)

  friend set set_difference (const set& s1, const set& s2);
// postcondition: difference of s1 - s2 has been returned
  // O(1 + 30 * contains() * insert()) = O(292801)

  friend bool is_subset (const set& s1, const set& s2);
  // postcondition: returned whether s1 is a subset of s2
  // O(intersection() + O(==)) = O(292831)

  friend bool operator == (const set& s1, const set& s2);
  // postcondition: returned whether s1 & s2 are equal
  //O(30)


  friend std::ostream& operator << (std::ostream& output, const set& s);
  // postcondition: s has been displayed on output
  // O(30)

private:
  size_type find (const value_type& entry) const;
  // returned location of entry in the set if entry is in the set - used otherwise
  // O(31)
  value_type* data;
  size_type capacity;
  size_type used;
};


#endif
