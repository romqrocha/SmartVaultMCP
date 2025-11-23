/*
*  
*  File:        StackTemplateClassDriver.cpp
*  Description: Used to test drive the Stack class
*
*  Author: Bob Langelaan
*  Date:	June 22, 2022
* 
*/

#include <iostream>
#include <iomanip>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> intStack;

	cout << "DEFAULT_CAPACITY for the Stack<int> class is: " << Stack<int>::DEFAULT_CAPACITY << endl << endl;

	cout << "The following values being pushed onto intStack." << endl;
	for (int i = 1; i <= 20; ++i)
	{
		cout << i << "  ";
		intStack.push(i);
	}

	cout << "\n\nThe following values were popped off intStack." << endl;
	while (!intStack.isEmpty())
	{
		cout << intStack.peek() << "  ";
		intStack.pop();
	}

	cout << endl << endl;

	Stack<double> doubleStack;

	cout << "DEFAULT_CAPACITY for the Stack<double> class is: " << Stack<double>::DEFAULT_CAPACITY << endl << endl;

	double value = 5.0;
	double increment = 5.0;
	
	cout << fixed << setprecision(2);
	cout << "The following values being pushed onto doubleStack." << endl;
	for (int i = 1; i <= 10; ++i)
	{
		cout << value << "  ";
		doubleStack.push(value);
		value += increment;
	}

	cout << "\n\nThe following values were popped off doubleStack." << endl;
	while (!doubleStack.isEmpty())
	{
		cout << doubleStack.peek() << "  ";
		doubleStack.pop();
	}

	cout << endl << endl;
}