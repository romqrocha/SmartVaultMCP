/*
* 
*  File:        Stack.cpp
*  Description: Implementation of the Stack class.
*
*  Author: Bob Langelaan
*  Date:   March 24th, 2025
* 
*/
#include <iostream>
#include "Stack.h"
using namespace std;

/*
*  Default constructor. Remember to initialize any variables you need
*  and allocate any required memory. The initial size of `items` should
*  be DEFAULT_CAPACITY defined in Stack.h.
*
*/

Stack::Stack()
	:items(new int[DEFAULT_CAPACITY]),num_items(0),max_items(DEFAULT_CAPACITY)
{
}

/*
*  Destructor. Remember to free any memory allocated.
*/
Stack::~Stack()
{
	delete[] items;
	items = nullptr;
	num_items = 0;
	max_items = 0;
}

/*
*  Copy ctor
*/
Stack::Stack(const Stack& orig)
	:items(new int[orig.max_items]), num_items(orig.num_items), max_items(orig.max_items)
{
	for (size_t i = 0; i < num_items; ++i)
	{
		items[i] = orig.items[i];
	}
}

/*
*  Overloaded copy = operator
*/
const Stack& Stack::operator = (const Stack& rhs)
{
	if (&rhs != this) //to avoid a self assignment
	{
		if (max_items != rhs.max_items) // resize array if necessary
		{
			delete[] items;
			max_items = rhs.max_items;
			items = new int[max_items];
		}

		num_items = rhs.num_items;

		// copy contents of array that matters
		for (size_t i = 0; i < num_items; ++i)
		{
			items[i] = rhs.items[i];
		}
	}

	return *this; // a = b = c;
}

/*
*  Adds the parameter object to the top of the Stack. That is, the
*  element should go at the end of the array. If the dynamic array
*  holding the stack elements is full the array should be resized. Resize should be
*  called by multiplying current capacity EXPANSION_FACTOR defined in Stack.h.
*  To be clear resize should happen before adding the element to the stack and only
*  when the stack is completely full.
*
*  PARAM: item - the object to be added to the Stack.
*/

void Stack::push(const int& item) {
	if (num_items >= max_items) //stack is full ?
	{
		resize(max_items * EXPANSION_FACTOR);
	}

	items[num_items++] = item;
};

/*
*  Removes the object on top of the Stack. That is, remove
*  the element at the end of the array. You may assume this function
*  is only called when the Stack is not empty. If the size of the stack changes
*  so that the ratio of num_items/max_items is less than the ratio of 
*  1.0 / SHRINK_RATE (where SHRINK_RATE is defined in Stack.h)
*  after the item is removed the Stack should be resized to the larger of max_items / EXPANSION_FACTOR,
*  or DEFAULT_CAPACITY.
*
*/

void Stack::pop() {
	--num_items;
	if (static_cast<double>(num_items) / max_items < 1.0 / SHRINK_RATE)
	{
		resize(max_items / EXPANSION_FACTOR > DEFAULT_CAPACITY ? max_items / EXPANSION_FACTOR : DEFAULT_CAPACITY);
	}
};

/*
*  Finds the object on top of the Stack, and returns it to the caller.
*  Unlike Pop(), this operation does not alter the Stack itself.
*  It should look at the end of the array. You may assume this function
*  is only called when the Stack is not empty.
* 
*  RETURN: the element at the top of the Stack.
*/

int Stack::peek() const{

	return items[num_items-1];
};

/*
*  Determines if the Stack is empty.
*  RETURN: true if the stack is empty,
*          false otherwise.
*/

bool Stack::isEmpty() const {
	return num_items == 0;
};

/*
*  Return the maximum number of items the stack can hold.
*
*  Note: This is an implementation detail we would normally hide.
*  We include it here for testing purposes.
* 
*  RETURN: maximum number of items the stack can hold (int)
*/

size_t Stack::capacity() const {
	return max_items;
};

/*
*  Return the number of items on the stack.
*  RETURN: number of items on the stack (int)
*/

size_t Stack::size() const {
	return num_items;
};

/*
*  Resize the the member variable `items`.
*  The minimum size is the number of items in the Stack.
*  PRE: n >= num_items, i.e. the new size has room for all items in the structure
*  PARAM: n - the capacity of the stack after resizing
*/

void Stack::resize(size_t n) {
	if (n < num_items)
	{
		// Something has gone very wrong!
		// Should probably throw exception here but will display an error message instead.
		cout << "ERROR!!! num_items < n in resize().  Will therefore not change size of arrray" << endl;
		return;
	}

	// The following may be true if pushing a value on a stack object that was
	// dynamically allocated and then deleted.
	if (max_items == DEFAULT_CAPACITY && n <= DEFAULT_CAPACITY)
	{
		return; // already as small as allowed
	}
	else if (n < DEFAULT_CAPACITY)
	{
		n = DEFAULT_CAPACITY; // limit downsizing to DEFAULT_CAPACITY
	}

	int* temp = new int[n]; // create new array that better meets needs of # of items on the stack
	
	// copy contents that matters from old array to new array
	for (size_t i = 0; i < num_items; ++i)
	{
		temp[i] = items[i];
	}

	delete[] items;  // delete old array
	items = temp; // make items point to new array
	max_items = n; // update max_items to size of new array
};
