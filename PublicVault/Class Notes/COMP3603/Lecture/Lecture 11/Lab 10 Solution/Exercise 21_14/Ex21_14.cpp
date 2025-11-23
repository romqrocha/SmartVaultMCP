// Exercise 21.14 Solution: Ex21_14.cpp
// Program creates a cryptogram from a string.
#include <iostream> 
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;

// prototype
void convertToLower( string::iterator, string::iterator );

int main()
{
   string s1;
   string alpha = "abcdefghijklmnopqrstuvwxyz";
   string::iterator is1; // used to iterate through s1
   string::iterator is2; // used to iterate through s2
   string::iterator is1mod; // secondary s1 iterator
   string::iterator is2mod; // secondary s2 iterator

   srand( time( 0 ) ); // random generator

   cout << "Enter a string to be converted into a cryptogram: \n\n";
   getline( cin, s1, '\n' ); // allow white space to be read
   cout << "\nThe original string :    " << s1;

   is1 = s1.begin(); // is1 points to the beginning of string s

   // function convertToLower runs through the end
   convertToLower( is1, s1.end() ); 

   string s2( s1 ); // instantiate s2 as a copy of s1
   
   is2 = s2.begin(); // is2 points to the beginning of s2

   do 
   {

      // do not change spaces or punctuation
      if ( (*is1 < 'a') || (*is1 > 'z') ) 
      {
         ++is1;
		 ++is2;
         continue;
      } 

      int x = rand() % alpha.length(); // pick letter
      char c = alpha[x];   // get letter
      alpha.erase( x, 1 ); // remove picked letter so that it
	                       //   cannot be used again

	  // do one replacement in s2 for sure

	  *is2 = c;  // replace with randomly chosen character

	  // init mod iterators

	  is1mod = is1;
	  is2mod = is2;

	  // and increment them both

	  ++is1mod;
	  ++is2mod;

      // iterate along s2 doing replacement for any additional
	  //    occurences of the same letter
      while ( is1mod != s1.end() ) 
      {
		  if ( *is1mod == *is1 ){
            *is2mod = c;    // replace with randomly chosen character
			*is1mod = ' ';  // modify s1 so that we don't replace
			                //   the letter a second time
		  }

         ++is2mod;
		 ++is1mod;

      } // end while
      
      ++is1; // position to next element in s1
      ++is2; // position to next element in s2

   } while ( is1 != s1.end() );

   cout << "\nCryptogram of string:    " << s2 << '\n' << endl; // output string

   system("pause");  // wait for user to signal completion
   return 0; // indicates successful termination
} // end main

// convert strings to lowercase characters
void convertToLower( string::iterator i, string::iterator end )
{
   // until the end is reached
   while ( i != end ) 
   {
      *i = tolower( *i );
      ++i;
   } // end while
} // end function convertToLower

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
