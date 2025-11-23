// Fig. 24.3: fig24_03.cpp
// Demonstrate shared_ptrs.

// Author: Bob Langelaan
// Date: November 1st, 2023

#include <algorithm> // required for sort()
#include <iostream>
#include <memory> // required for shared_ptr<> template class
#include <vector>
#include "Book.h"
using namespace std;

typedef shared_ptr< Book > BookPtr; // shared_ptr to a Book object
typedef shared_ptr< Book[] > BookPtr2; // shared_ptr to an array of Book objects

// a custom delete function for a pointer to a Book
void deleteBook( Book* book )
{
   cout << "Custom deleter for a Book, ";
   delete book; // delete the Book pointer
} // end of deleteBook

// compare the titles of two Books
// binary predicate function
bool compareTitles( BookPtr bookPtr1, BookPtr bookPtr2 )
{
   return ( bookPtr1->title < bookPtr2->title );
} // end of compareTitles

int main()
{
    // create a shared_ptr to a Book and display the reference count
    Book* bPtr = new Book("C++ How to Program");
    BookPtr bookPtr(bPtr);
    cout << "Reference count for Book " << bookPtr->title << " is: "
        << bookPtr.use_count() << endl;

    // create another shared_ptr to the Book and display reference count
    BookPtr bookPtr2(bookPtr); //Invokes copy ctor of the shared pointer class
    //BookPtr bookPtr2(bPtr); //Doing this instead is incorrect! We end up with both
                              //  shared pointers believing they are the only pointer
                              // to the resource.

    cout << "Reference count for Book " << bookPtr2->title << " is: "
        << bookPtr.use_count() << endl;

    // change the Book's title and access it from both pointers
    bookPtr2->title = "Java How to Program";
    cout << "\nThe Book's title changed for both pointers: "
        << "\nbookPtr: " << bookPtr->title
        << "\nbookPtr2: " << bookPtr2->title << endl;

    // Use the BookPtr2 typedef to create a shared pointer to an array of Books
    BookPtr2 bookArrPtr(new Book[5]); //Will use the default ctor to initialize each of them

    // create a std::vector of shared_ptrs to Books (BookPtrs)
    vector< BookPtr > books;
    books.push_back(BookPtr(new Book("C How to Program")));
    books.push_back(BookPtr(new Book("VB How to Program")));
    books.push_back(BookPtr(new Book("C# How to Program")));
    books.push_back(BookPtr(new Book("C++ How to Program")));

    // print the Books in the vector
    cout << "\nBooks before sorting: " << endl;
    for (int i = 0; i < books.size(); ++i) {
        cout << (books[i])->title << "\n";
    }

    // sort the vector by Book title and print the sorted vector
    sort(books.begin(), books.end(), compareTitles);

    cout << "\nBooks after sorting: " << endl;
    for (int i = 0; i < books.size(); ++i) {
        cout << (books[i])->title << "\n";
    }

   // create a shared_ptr with a custom deleter
   cout << "\nshared_ptr with a custom deleter." << endl;
   BookPtr bookPtr3( new Book( "Small C++ How to Program" ), deleteBook );
   BookPtr bookPtr4(bookPtr3);
   bookPtr4.reset(); //This will not cause previous book to be destroyed because reference count will not be 0
   bookPtr3.reset(); // release the Book this shared_ptr manages
// bookPtr3.reset(new Book ("Dune")); // If we did this instead of previous line of code,
//                                    //  the smart pointer bookPtr3 would release the old book       
//                                    //  and assign new book to the smart pointer
// 

   // shared_ptrs are going out of scope
   cout << "\nAll shared_ptr objects are going out of scope." << endl;
} // end of main

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
