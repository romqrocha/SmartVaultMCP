// Fig. 24.10: fibonacci.cpp
// Fibonacci calculations performed sequentially
// Modified by Bob Langelaan
// Date: March 31, 2022

// NOTE: We display result for fib(48) twice to prevent opitimization by the compiler which would cause 
//       total time for calculating fib(48) to display as 0.

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

unsigned long long int fibonacci( unsigned int n ); // function prototype

// function main begins program execution
int main( void )
{
   cout << fixed << setprecision( 6 );
   cout << "Sequential calls to fibonacci(47) and fibonacci(48)" << endl;

   // calculate fibonacci values for numbers 48 (line 26) and 47 (line 38)
   cout << "Calculating fibonacci( 48 )" << endl;
   time_t startTime1 = time( nullptr );
   
   unsigned long long int result1 = fibonacci( 48 ); 
   time_t endTime1 = time(nullptr);
  
   cout << "fibonacci( 48 ) = " << result1 << endl;
   
   cout << "Calculation time = " 
      << (endTime1 - startTime1 ) / 60.0 
      << " minutes\n" << endl; 
   cout << "fibonacci( 48 ) = " << result1 << endl;
 
   cout << "Calculating fibonacci( 47 )" << endl;
   time_t startTime2 = time( nullptr );
   unsigned long long int result2 = fibonacci( 47 );

   cout << "fibonacci( 47 ) = " << result2 << endl;
   time_t endTime2 = time(nullptr);
   cout << "Calculation time = " 
       << (endTime2 - startTime2) / 60.0
      << " minutes\n" << endl; 

   cout << "Total calculation time = " 
       << (endTime2 - startTime1) / 60.0 << " minutes" << endl;
} // end main

// Recursively calculates fibonacci numbers
unsigned long long int fibonacci( unsigned int n )   
{                                                    
   // base case                                      
   if ( 0 == n || 1 == n ) 
   {                         
      return n;                                      
   } // end if                                       
   else // recursive step
   { 
      return fibonacci( n - 1 ) + fibonacci( n - 2 );
   } // end else                                     
} // end function fibonacci 


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
