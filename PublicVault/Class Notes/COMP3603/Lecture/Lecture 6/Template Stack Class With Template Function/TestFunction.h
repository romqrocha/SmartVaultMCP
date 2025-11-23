// Author: Bob Langelaan
// Date: March 24th, 2025

#ifndef _TEST_FUNCTION_H_
#define _TEST_FUNCTION_H_

#include <iostream>
#include <string>
#include "Stack.h" // Stack class template definition
using namespace std;

// function template to test drive Stack<T>  
template <typename T, size_t size>// size is # of items to push
void TestFunction(
    Stack< T >& theStack, // reference to Stack< T >         
    const T& value, // initial value to push                        
    const T& increment, // increment for subsequent values  
    const string& stackName) // name of the Stack< T > object
{
    cout << "The following values being pushed onto " << stackName << ".\n";
    T pushValue = value;

    // push element onto Stack                               
    for (size_t i = 0; i < size; ++i)
    {
        theStack.push(pushValue); // push element onto Stack
        cout << pushValue << ' ';
        pushValue += increment;
    } // end while

    cout << "\n\nThe following values were popped off " << stackName << ".\n";

    // pop elements from Stack                               
    while (!theStack.isEmpty()) // loop while Stack is not empty
    {
        cout << theStack.peek() << ' ';
        theStack.pop(); // remove top element
    } // end while
} // end function template testStack   

#endif