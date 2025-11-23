// Practice Assignment 2 Solution: Fraction.cpp
// Member-function definitions for class Fraction.
// 
// Modified to demo increment and decrement operators and overloaded << operator
// 
// Author: Bob Langelaan 
// Date:   Feb 10th, 2022

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

//default ctor
Fraction::Fraction (void)
	:numerator(0), denominator(1)
{}

//ctor - requires 2 paramaters
Fraction::Fraction ( long long num, long long denom )
	:numerator(num), denominator(denom)
{
	if (denominator == 0){
		numerator = 0;
		denominator = 1;
		cerr << "\n\n Attempt was made to create a Fraction object with a denominator of 0 !!!\n\n";
	}

	else{
		simplify();
	}
}

// Implementation of plusEq() member function
//Performs similar operation as the += operator on the built-in types
const Fraction & Fraction::plusEq (const Fraction & op )
{

/*
	The following solution that I have commented out 
		is simpler but perfectly fine as well!

	numerator = numerator * op.denominator + op.numerator * denominator;
	denominator *= op.denominator;

	simplify();
	return (*this);

*/

	if (denominator != op.denominator )
	{ // Compute smallest common denominator using gcd()
	  //         and add 2 fractions
		long long common_divisor = gcd(denominator,op.denominator);
		numerator *= (op.denominator / common_divisor);
		numerator += op.numerator * (denominator / common_divisor);
		denominator *= (op.denominator / common_divisor);
	}
	else 
	{
		numerator += op.numerator;
	}

	simplify();
	return (*this);
}


// Implementation of the minusEq() member function
//Performs similar operation as the -= operator on the built-in types
const Fraction & Fraction::minusEq (const Fraction & op )
{

/*
	The following solution that I have commented out 
		is simpler but perfectly fine as well!

	numerator = numerator * op.denominator - op.numerator * denominator;
	denominator *= op.denominator;

	simplify();
	return (*this);

*/

	if (denominator != op.denominator )
	{ // Compute smallest common denominator using gcd()
	  //         and subtract 2 fractions
		long long common_divisor = gcd(denominator,op.denominator);
		numerator *= (op.denominator / common_divisor);
		numerator -= op.numerator * ( denominator / common_divisor);
		denominator *= (op.denominator / common_divisor);
	}
	else
	{
		numerator -= op.numerator;
	}

	simplify();

	return (*this);
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq (const Fraction & op)
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

//Implementation of the divideEq() member function
//Performs similar operation as the /= operator on the built-in types
const Fraction & Fraction::divideEq (const Fraction & op )
{
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();

	return (*this);
}

//Implementation of the negate() member function
//Performs similar operation as the unary - operator on the built-in types
Fraction Fraction::negate ( void )const 
{
	return (Fraction(-(numerator), (denominator)));
}

//This member function ensures that the denominator is not negative
//   and uses the gcd template function to reduce the fraction as much as 
//   possible
void Fraction::simplify(void)
{
	if (denominator < 0 ) //correct sign if necessay
	{
		numerator = - numerator;
		denominator = - denominator;
	}

	if (numerator == 0 )
	{
		denominator = 1;
	}

	// Reduce by dividing by gcd, if gcd > 1

	else
	{
		long long  gcd_val =  gcd (numerator, denominator);
		if (gcd_val > 1)
		{
			numerator /= gcd_val;
			denominator /= gcd_val;
		}
	}
}

// returns the numerator of the Fraction object
long long Fraction::getNum(void)const
{
	return numerator;
}

// returns the denominator of the Fraction object
long long Fraction::getDenom(void)const
{
	return denominator;
}

// displays the fraction object
void Fraction::display (void)const
{
	cout << numerator << '/' << denominator;
}

// overlaod << operator for the Fraction class
ostream& operator << (ostream& os, const Fraction& rhs)
{
	os << rhs.getNum() << '/' << rhs.getDenom();
	return os;
}

// pre increment
Fraction& Fraction::operator ++()
{
	numerator += denominator;
	return* this;
}

// post increment
Fraction Fraction::operator ++(int)
{
	Fraction temp = *this;
	numerator += denominator;
	return temp; // return original value
}

// pre decrement
Fraction& Fraction::operator --()
{
	numerator -= denominator;
	return*this;
}

// post decrement
Fraction Fraction::operator --(int)
{
	Fraction temp = *this;
	numerator -= denominator;
	return temp; // return original value
}


