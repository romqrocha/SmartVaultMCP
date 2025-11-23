/*
*  
*  File:        StackClassDriver.cpp
*  Description: Used to test drive the Stack class
*
*  Author: Bob Langelaan
*  Date:   October 19th, 2022
* 
*/

#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack intStack;

	cout << "The following values were pushed onto intStack." << endl;
	for (int i = 1; i <= 20; ++i)
	{
		cout << i << "  " << endl;
		intStack.push(i);
		cout << "capacity = " << intStack.capacity() << endl << endl;
	}

	cout << "\n\nThe following values were popped off intStack." << endl;
	while (!intStack.isEmpty())
	{
		cout << intStack.peek() << "  " << endl;
		intStack.pop();
		cout << "capacity = " << intStack.capacity() << endl << endl;;
	}

	cout << endl << endl;
}