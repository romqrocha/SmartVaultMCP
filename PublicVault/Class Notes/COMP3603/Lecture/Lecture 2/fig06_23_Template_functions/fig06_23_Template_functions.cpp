// Fig. 6.23: fig06_23.cpp
// Function template maximum test program.
// Last modified: Sept 20, 2023

#include <iostream>
#include <string>
#include "maximum.h" // include definition of function template maximum
using namespace std;

int main() {
   // demonstrate maximum with int values
   cout << "Input three integer values: ";
   int int1, int2, int3;
   cin >> int1 >> int2 >> int3;

   // invoke int version of maximum
   cout << "The maximum integer value is: "
      << maximum(int1, int2, int3); // implicitly uses the template function     

   // demonstrate maximum with double values
   cout << "\n\nInput three string values: ";
   string s1, s2, s3;
   cin >> s1 >> s2 >> s3;

   // invoke double version of maximum
   cout << "The maximum string value is: "
      << maximum(s1, s2, s3);  // implicitly uses the template function 

   // demonstrate maximum with char values
   cout << "\n\nInput three characters: ";
   char char1, char2, char3;
   cin >> char1 >> char2 >> char3;

   // invoke char version of maximum
   cout << "The maximum character value is: "
      << maximum<char>(char1, char2, char3) << endl; // explicitly uses the template function 
} // end main


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
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
