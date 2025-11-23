/*
*  
*  File:        StackTemplateClassDriver.cpp
*  Description: Used to test drive the Stack class.
*               Uses template function to do the majority of the work.
* 
*  Author: Bob Langelaan
*  Date:	Feb 24th, 2022
* 
*/

#include <iostream>
#include <iomanip>
#include "Stack.h" // template class
#include "TestFunction.h" // template function

using namespace std;

int main()
{
	Stack<int> intStack;
	string name = "intStack";
	TestFunction(intStack,1,1,20,name); //implicitly invoke template function
	cout << endl << endl;
	
	Stack<double> doubleStack;
	name = "doubleStack";
	cout << fixed << setprecision(2);
	TestFunction<double>(doubleStack,5.0,5.0,10,name); //explicitly invoke template function

	cout << endl << endl;
}