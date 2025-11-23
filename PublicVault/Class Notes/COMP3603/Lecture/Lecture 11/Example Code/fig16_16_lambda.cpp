/* This document is meant to be a tutorial on Lambda Expressions.
   I have borrowed most of the content of this doc from 
   "C++ 11 Rocks" by Alex Korban.  A higly recommended book if you
   want to learn more about C++ 11 & 14.                             */

// Author: Bob Langelaan
// Date: June 12, 2016
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
   const size_t SIZE = 10; // size of array values
   array< int, SIZE > values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // initialize values

   // output each element multiplied by two
   for_each( values.cbegin(), values.cend(),
      []( int i ) { cout << i * 2 << endl; } );

   int sum = 0; // initialize sum to zero

   // add each element to sum
   for_each( values.cbegin(), values.cend(),
      [ &sum ]( int i ) { sum += i; } );

   cout << "\nsum is " << sum << endl; // output sum
} // end main

