/*
*  
*  File:        StackTemplateClassDriver.cpp
*  Description: Used to test drive the Stack class
*
*  Author: Bob Langelaan
*  Date:	Feb 24th, 2022
* 
*/

#include <iostream>
#include <iomanip>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> intStack;

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