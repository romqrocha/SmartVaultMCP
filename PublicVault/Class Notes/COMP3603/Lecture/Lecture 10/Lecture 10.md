# Topics Covered
1. Chapter 15 - Standard Library Containers and Iterators  
	- Fig 15.14 to Fig15.21 inclusive  
	- [[cpphtp9_15_revised.pdf|Chapter 15 slides]] 196 to 202 inclusive - An introduction to bitsets  
2. Chapter 16 - Standard Library Algorithms  
	1. [[cpphtp9_16_revised.pdf|Chapter 16 slides]] 6 to 14 inclusive - Section 16.2 Minimum Iterator Requirements  
	2. Fig 16.01 and Fig16.05
# Set
- Cannot contain duplicates
- Template is `set<type, stort_type>`
	- E.g. `set<int, less<int>>`
	- Default is smallest-to-largest
# Multiset
- Like a set, but allows duplicates
- Template is `multiset<type, stort_type>`
	- E.g. `multiset<int, less<int>>`
	- Default is smallest-to-largest
- You can use the `count(T value)` method to count instances of something in the multiset.
- `.upper_bound(T value)` returns the item AFTER the last instance of the value passed in
# Multimap
- Allows for duplicates
- Requires a key: value pair
- Template is `multimap< keyType, valueType, sortType >`
	- E.g. `multimap<int, float, less<int>>`
- You can insert a `pair` object using `insert(make_pair(keyType, valueType))`
# Bit set
- A set that contains only 0 and 1
- Fixed in size at compile time
- Useful when you need to contain a lot of data that needs to be in binary states(on/off, true/false)
- All bits are set to 0 by default
- `bitset<size>`
- Set bits with `.set(bitNumber)` or set all bits with `.set()`
- Invert all values with  `.flip()` or a specific value with `.flip(bitNumber)`
# Iterator Invalidation
- Because iterators point to a container element, its possible for an iterator to become invalid if the container is modified
	- E.g. If you clear all elements from a vector, the iterator is invalid
- Less obvious examples, when inserting into a 
	- vector:
		- if the vector is reallocated, all iterators pointing to the vectors are now invalid
		- if not reallocated, any iterator from the insertion point to the end are invalid
	- deque:
		- All iterators are invalidated
	- Unordered Associative Container:
		- Invalidated if the container needs to be reallocated
# Fill
- Algorithm that fills a container with a value
- https://cplusplus.com/reference/algorithm/fill/
- `fill(container.begin(), container.end(), val)`
# Generate
- Like Fill
- Can take a function name, pointer, lambda, or functor
# For Each
- An algorithm that runs a passed in function on each items in a container
- Lots of similar algorithms; `count_if`, `min_element`, `max_element`, and `transform`