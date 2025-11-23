// Author: Bob Langelaan
// Date:   May 17th, 2023

#include <iostream>
#include <array> // C++ 11
#include <vector>
using namespace std;

int main()
{
	// create a C array, a stl array and a stl vector
	int myArray1[10]{ 1,2,3,4,5,6,7,8,9,10 };  // 40 bytes on the stack
	array<int, 10> myArray2{ 1,2,3,4,5,6,7,8,9,10 }; // also 40 bytes on the stack. No overhead bytes!
	vector<int> myArray3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 16 overhead bytes on the stack and 40 bytes on the free store (heap)
														   //  for a 32 bit app
	cout << "The size of C array myArray1 is: " << sizeof myArray1 << endl;
	cout << "The size of stl array object myArray2 is: " << sizeof myArray2 << endl;
	cout << "The size of stl vector object myArray3 is: " << sizeof myArray3 << endl << endl;

	// increase size of vector object by adding a new value to the end of the vector
	// myArray3[10] = 11; // runtime error
	myArray3.push_back(11); //Add the value 11 to back of vector
	myArray3[10] = 20; //ok now because size of vector was increased by 1 in the previus statement

	cout << "Contents of myArray1: ";
	for (size_t i = 0; i < 10; ++i)
	{
		cout << myArray1[i] << "  ";
	}
	cout << endl;

	cout << "Contents of myArray2: ";
	for (size_t i = 0; i < myArray2.size(); ++i)
	{
		cout << myArray2[i] << "  ";
	}
	cout << endl;

	cout << "Contents of myArray3: ";
	for (size_t i = 0; i < myArray3.size(); ++i)
	{
		cout << myArray3[i] << "  ";
	}
	cout << endl;

	// ================================================

	array<int, 10> myArray4;  // define another array object the same size and type as myArray2
	vector<int> myArray5; // define another vector object, the same type but not the same size as myArray3

	// examples of use of the overloaded = operator for the 2 stl classes
	myArray4 = myArray2; // note they are the same size
	myArray5 = myArray3; // note they are NOT the same size - myArray5 has size 0 before assignment

	if (myArray4 == myArray2)
	{
		cout << "\nmyArray4 is equal to myArray2" << endl;
	}

	if (myArray5 == myArray3)
	{
		cout << "myArray5 is equal to myArray3" << endl;
	}

	// The following will not work because the 2 stl arrays are not the same size

	array<int, 11> myArray6;
//	myArray6 = myArray4; // will not compile
//	if (myArray6 == myArray4); // will not compile

	// As we saw above when we assigned myArray3 to myArray5, the 2 vector objects 
	// do not need to be the same size when assigning one vector object to another.

}
