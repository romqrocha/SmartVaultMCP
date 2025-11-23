// Practice Assignment 2 Main Program - used to "test drive" the Fraction class
// File Name: MainProg.cpp
// 
// Modified to demo increment and decrement operators and overloaded << operator
// 
// Author: Bob Langelaan 
// Date:   Feb 10th, 2022

#include <iostream>
#include "Fraction.h" // include definition of class Fraction from Fraction.h
#include "GCD.h"      // include definition of gcd template function
using namespace std;

int main()
{
	Fraction f1(-3, 5);
	cout << f1++ << endl;
	cout << ++f1 << endl;
	cout << f1 << endl << endl;

	Fraction f2(9, 7);
	cout << --f2 << endl;
	cout << f2-- << endl;
	cout << f2 << endl;

} // end main

