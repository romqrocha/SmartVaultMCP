// Exercise 21_12 Solution: Ex21_12.cpp
#include <iostream> 
#include <string> 
using namespace std;

int main()
{
   string s;

   cout << "Enter a string: ";
   getline( cin, s, '\n' );

   // r is set to the beginning of the reverse sequence from s
   string::reverse_iterator r = s.rbegin();

   // loop till the reversed end if reached
   while ( r != s.rend() ) 
   {
      // convert all characters to its opposites
      *r = ( isupper( *r ) ? tolower( *r ): toupper( *r ) );
      cout << *( r++ ); // next character
   } // end loop

   cout << endl;
   system("pause");  // wait for user to signal completion
   return 0; // indicates successful termination
} // end main

/**************************************************************************
 * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
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
