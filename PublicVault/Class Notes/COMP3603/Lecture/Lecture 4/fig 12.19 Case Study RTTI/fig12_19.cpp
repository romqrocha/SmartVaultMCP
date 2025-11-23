// Modified by: Bob Langelaan
// Date: Feb 03, 2022

// Fig. 12.19: fig12_19.cpp
// Demonstrating downcasting and runtime type information.
// NOTE: You may need to enable RTTI on your compiler
// before you can compile this application.
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
//#include "Employee.h"
#include "SalariedEmployee.h" // derived from Employee class
//#include "CommissionEmployee.h"  // derived from Employee class
#include "BasePlusCommissionEmployee.h" // derived from CommissionEmployee class
using namespace std;

int main()
{
   // set floating-point output formatting
   cout << fixed << setprecision( 2 );   

   CommissionEmployee BobL("Bob", "Instructor", "222-22-2222", 1000000, .05);
   
   // create vector of three base-class pointers
   vector < Employee * > employees( 3 );

   // initialize vector with various kinds of Employees
   employees[ 0 ] = new SalariedEmployee( 
      "John", "Smith", "111-11-1111", 800 );
   employees[ 1 ] = new CommissionEmployee( 
      "Sue", "Jones", "333-33-3333", 10000, .06 );
   employees[ 2 ] = new BasePlusCommissionEmployee( 
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

   // polymorphically process each element in vector employees
   for ( Employee *employeePtr : employees ) 
   {
      if (employeePtr == nullptr)
      {
         continue;
      }
      employeePtr->print(); // output employee information
      cout << endl;

      // Must be an exact match in regards to type in order to be true
      // There is also a != overloaded operator
      // typeid operator returns a type_info object which CANNOT be assigned to a variable
      if (typeid(*employeePtr) == typeid(BobL)) // Uses overload == operator
      {
          cout << "Same type of object as BobL :)\n";
      }

      // downcast pointer
      // 
      // Note that if we were casting to CommissionEmployee pointer instead,
      //   both the CommissionEmployee pointer and the BasePlusCommissionEmployee
      //   pointer would be successfully downcast
      BasePlusCommissionEmployee *derivedPtr =
        dynamic_cast < BasePlusCommissionEmployee * >( employeePtr );

      // determine whether element points to a BasePlusCommissionEmployee 
      if ( derivedPtr != nullptr ) // true for "is a" relationship
      {
         double oldBaseSalary = derivedPtr->getBaseSalary();
         cout << "old base salary: $" << oldBaseSalary << endl;
         derivedPtr->setBaseSalary( 1.10 * oldBaseSalary );
         cout << "new base salary with 10% increase is: $" 
            << derivedPtr->getBaseSalary() << endl;
      } // end if
      
      cout << "earned $" << employeePtr->earnings() << "\n\n";
   } // end for   
 
   // release objects pointed to by vector’s elements
   for ( const Employee *employeePtr : employees ) 
   {
      // output class name
      cout << "deleting object of " 
         << typeid( *employeePtr ).name() << endl;

      delete employeePtr;
   } // end for
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
