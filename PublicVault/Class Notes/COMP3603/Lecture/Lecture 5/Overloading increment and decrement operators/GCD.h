// Practice Assignment 2 Solution: GCD.h
// Template definition for gcd() function which calculates the
//    greatest common divisor
// Author: Bob Langelaan
// Date: Jan 26th, 2022

template <class T>
T gcd(T x,T y )
{
	T greatest{ 1 }; // current greatest common divisor, 1 is minimum

   if (x < 0) // compute abs of x
   {
	   x = -x;
   }

   if (y < 0) // compute abs of y
   {
	  y = -y;
   }

   // loop from 2 to smaller of x and y
   for ( T i = 2; i <= ( ( x < y ) ? x: y ); i++ )
   {
      // if current i divides both x and y
      if ( x % i == 0 && y % i == 0 )
	  {
         greatest = i; // update greatest common divisor
	  }
   } // end for

   return greatest; // return greatest common divisor found
} // end function gcd