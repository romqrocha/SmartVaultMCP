// Author: Bob Langelaan
// Date:   Jan 25, 2022

#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main()
{
	// create a C array, a stl array and a stl vector
	int myArray1[10]{ 1,2,3,4,5,6,7,8,9,10 };  // 40 bytes on the stack
	array<int, 10> myArray2{ 1,2,3,4,5,6,7,8,9,10 }; // also 40 bytes on the stack. No overhead bytes!
	vector<int> myArray3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 16 overhead bytes on the stack and 40 bytes on the free store (heap)

	auto value = myArray1[0]; // compiler figures out for us what type value should be based on type of value assigned to it.

	cout << "Values in myArray3: ";
	for (const auto & val : myArray3) // compiler figures out what type val should be
	{
		cout << val << "  ";
		// val *= 2; // will not compile
	}
	cout << endl;

	cout << "Values in myArray2: ";
	auto it = myArray2.cbegin(); // it is a const iterator of the type required, thanks to the auto keyword
	for (; it != myArray2.cend(); ++it) // note that end() returns an iterator to element one position past the last element!
	{
		cout << *it << "  ";
		// *it *= 2; // will not compile
	}
	cout << endl;

}