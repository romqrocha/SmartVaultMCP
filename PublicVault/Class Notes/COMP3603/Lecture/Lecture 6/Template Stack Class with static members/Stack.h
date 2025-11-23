/*
* 
*  File:        Stack.h
*  Description: Definition of the template Stack class.
*
*  Author: Bob Langelaan
*  Date:   June 14th, 2023
*
*/

#ifndef _STACK_H_
#define _STACK_H_

template<typename T>
class Stack {
  public:
    /*
    *  Default constructor
    */
    Stack();

    /*
    *  Copy ctor
    */
    Stack(const Stack& orig);

    /*
    *  Destructor
    */
    ~Stack();

    /*
    *  Overloaded copy = operator
    */
    const Stack& operator = (const Stack& rhs);

   
    /*
    *  Adds the parameter object to the top of the Stack
    *  PARAM: item - the object to be added to the Stack
    *  POST:  the Stack contains newitem at the top, as its most recently added item.
    */
    void push(const T & item);

    /*
    *  Removes the object on top of the Stack.
    *  POST: the most recently added item is removed from the collection.
    */
    void pop();


    /*
    *  Finds the object on top of the Stack, and returns it to the caller.
    *  Unlike Pop(), this operation does not alter the Stack itself.
    *  RETURN: the element at the top of the Stack.
    */
    T peek()const;

    /*
    *  Determines if the Stack is empty.
    *  RETURN: true if the stack is empty,
    *          false otherwise.
    */
    bool isEmpty() const;

    /*
    *  Return the maximum number of items the stack can hold.
    *
    *  Note: This is an implementation detail we would normally hide.
    *  We include it here for testing purposes.
    */
    size_t capacity() const;

    /*
    *  Return the number of items on the stack.
    */
    size_t size() const;

    // public static members
    const static size_t DEFAULT_CAPACITY = 4; // Initial capacity of the array.
    const static size_t EXPANSION_FACTOR = 2; // Factor to multiply or divide current size by when resizing.
    const static size_t SHRINK_RATE = 4;      // When the ratio of (array use / array size) is less than 
                                              // 1 over this value, the array should resize downwards

  private:
    /*
    *  The maximum number of items the stack can store without a resize
    */
    size_t max_items;

    /*
    *  The number of items currently in the stack
    */
    size_t num_items;

    /*
    *  The dynamic array representing our Stack
    */
    T* items;

    /*
    *  Resize the the member variable `items`.
    *  The minimum size is the number of items in the Stack.
    *  Don't forget to free up any memory that is no longer used.
    *  PARAM: n - the capacity of the stack after resizing
    */
    void resize(size_t n);
};

#include "Stack_inc.h"
#endif
