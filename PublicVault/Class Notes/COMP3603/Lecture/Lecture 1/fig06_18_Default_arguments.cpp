// Fig. 6.18: fig06_18.cpp
// Using default arguments.
#include <iostream>
using namespace std;

// function prototype that specifies default arguments
unsigned int boxVolume(unsigned int length = 2, unsigned int width = 5,
   unsigned int height = 3);

int main() {
   // no arguments--use default values for all dimensions
   cout << "The default box volume is: " << boxVolume();

   // specify length; default width and height
   cout << "\n\nThe volume of a box with length 10,\n"
      << "width 5 and height 3 is: " << boxVolume(10);

   // specify length and width; default height
   cout << "\n\nThe volume of a box with length 10,\n"
      << "width 2 and height 3 is: " << boxVolume(10, 2);

   // specify all arguments 
   cout << "\n\nThe volume of a box with length 10,\n"
      << "width 5 and height 2 is: " << boxVolume(10, 5, 2)
      << endl;

   /* 
   
   Note that the following will not compile:
   
   boxVolume(10,,2);  //attmpting to use only default value for width

   Default values MUST be used from right to left!!!
   And therefore, for examample, you cannot supply a default value for the
      2nd from the right paramter with out also supplying a default value 
      for the right most parameter.

   */
}

// function boxVolume calculates the volume of a box
// note you may not specify defaults again below!
unsigned int boxVolume(unsigned int length, unsigned int width,
   unsigned int height) {
   return length * width * height;
}


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
