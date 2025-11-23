// Exercise 15.22 Solution: Ex15_22.cpp
#include <iostream> 
#include <vector> // vector class-template definition
using namespace std;

// function template palindrome definition
template < typename X >
bool palindrome( const vector< X > &vec )
{
   auto r = vec.crbegin();
   auto i = vec.cbegin();

   while ( r != vec.crend() && i != vec.cend() )  
   {
      if ( *r != *i ){ // values are not equal
         return false;
	  }

      ++r;
      ++i;
   } // end while 

   return true; // the vector is a palindrome
} // end function palindrome

// function template printVector definition
template < typename Y >
void printVector( const vector< Y > &vec )
{
   for ( auto i = vec.cbegin(); i != vec.cend(); ++i ){
      cout << *i << ' ';
   }

} // end function palindrome

int main()
{
   vector< int > vi;  // vector of "int"s
   vector< char > vc; // vector of "char"s
   
   int intNumber;
   int charNumber;

   int value;
   char c;

   cout << "How many ints will you enter: ";
   cin >> intNumber;

   for (int i = 1; i <= intNumber; ++i)
   {
       cin >> value;
       vi.push_back(value);
   }
   
   printVector( vi );
   cout << ( palindrome( vi ) ? " is " : " is not " ) << "a palindrome\n";

   cout << "\nHow many chars will you enter: ";
   cin >> charNumber;

   for (int i = 1; i <= charNumber; ++i)
   {
       cin >> c;
       vc.push_back(c);
   }

   printVector( vc );
   cout << ( palindrome( vc ) ? " is " : " is not " ) << "a palindrome\n";

   system("pause");

   return 0;

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
