# Standard Template Library
- 3 main components:
	1. Containers
	2. Iterators
	3. Algorithms
# Containers
> [!note] A data structure capable of storing objects of *almost* any type

3 types:
1. First-Class containers
2. Container Adapters
3. Near Containers

4 categories:
1. Sequence Containers - Linear data structures
	- array
	- deque
	- forward_list - Singly linked-list
	- list - doubly linked list
	- vector
2. Ordered Associative - Non-linear; Keys are maintained in a sorted order
	- set
	- multiset - duplicated allowed
	- map - One-to-one mapping
	- multimap - One-to-many mapping; duplicates allowed
3. Unordered Associative Containers - Non-linear
	- unordered_set
	- unordered_multiset
	- unordered_map
	- unordered_multimap
4. Container Adapters
	- stack
	- queue
	- priority_queue

- When objects are inserted, a **copy** is put in, so make sure your objects have a Copy Constructor and Copy Assignment Operator
- Lots of algorithms need to check for equality or relative values
	- At bare minimum, overload Less Than(<) and Equality = = operators  
# Iterators
- Exist as an interface between Containers and Algorithms
- requires a `begin()` and `end()` function in the class to be iterated over
	- Begin returns the first element
	- End returns one **past** the last element
- Its important for iterators to overload the deference operator(`*`) and increment operator so you can dereference the iterator to access the data, and move across the elements