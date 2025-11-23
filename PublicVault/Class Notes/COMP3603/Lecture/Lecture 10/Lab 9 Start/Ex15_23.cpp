// Exercise 15.23: Ex15_23.cpp
// Using a bitset to demonstrate the Sieve of Eratosthenes.
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <bitset> // bitset class definition
#include <ctime>
using namespace std;

int main()
{
   // SIZE is set to 1 billion, but should work up to max value of size_t, which is over 4 billion.
   const size_t SIZE = 1000000000; //must be an even # for PARTS 2 & 3 of my solution to work correctly

   //The bitset cannot be stored on the stack if it is very large.
   bitset< SIZE> & sieve = * (new bitset< SIZE >); // create bitset of SIZE bits on the free store

   // equivalent to:
   // bitset< SIZE > sieve;  // would be stored on stack

   time_t start_time;    /* used to store starting time */
   time_t end_time;      /* used to store end time */
   time_t total_time;    /* used to compute total time to compute solution */

   start_time = time(NULL); // record start time

   // Any other required initialization 




   // PART 1 - perform Sieve of Eratosthenes

   

   // PART 2 - count prime numbers in range 2 to SIZE

  
   
   cout << "The number of prime #s between 2 and " << SIZE << " is: " << primeCount << '\n';

   // PART 3 - Find first prime less than SIZE


   
   cout << "The first prime # less than " << SIZE << " is: " << value << '\n';

   end_time = time(NULL); // record end time
   total_time = end_time - start_time; // calculate time to compute PARTS 1 to 3
   cout << "\n\nIt took " << static_cast<long>(total_time) << " seconds to compute PARTS 1 to 3\n" << endl;

   // PART 4 - get value(s) from user to determine whether value is prime

  



   // Free up memory allocated from the heap
   delete &sieve;

   system("pause");

} // end main


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
