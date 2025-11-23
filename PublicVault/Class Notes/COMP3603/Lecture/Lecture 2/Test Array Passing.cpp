// Author: Bob Langelaan
// Date:   Jan 23, 2022

// Teaches some lessons on differences between C array and stl array and vector

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>

using std::cout;

// prototypes for 5 functions that pass an array of ints 
void func1(int []); // pass C-style array of dynamic size
void func2(std::array<int,10> &); // pass stl array of size 10
void func3(std::vector<int> &); // pass stl vector of dynamic size
void func4(int []); // pass C-style array of dynamic size
void func5(int * const); // can also be used to pass C-style array of dynamic size

// NOTE: There is essentially no difference between func4() and func5() prototypes

int main()
{
	// Note that the code below up to the call to func() has no compile errors
	int myArray1[10] {10,1,9,2,8,3,7,4,6,5}; //C-style array

	std::array<int,10> myArray2 {10,1,9,2,8,3,7,4,6,5}; // STL array

	std::vector<int> myArray3 { 10, 1, 9, 2, 8, 3, 7, 4, 6, 5 };

	// What will sizeof operator find for each container?
	cout << "sizeof C-style array with 10 int elements is: " << sizeof myArray1;
	cout << "\n\nsizeof STL array with 10 int elements is: " << sizeof myArray2;
	cout << "\n\nsizeof STL vector with 10 int elements is: " << sizeof myArray3;

	cout << "\n";

	// Invoke the 3 functions

	func2(myArray2); // STL array
	func3(myArray3); // STL vector

	func1(myArray1); // C-style array

	// The following code works with C-style array where array declaration is in the same scope

	std::sort(std::begin(myArray1),std::end(myArray1));

	cout << "\n\n";
	for ( auto value : myArray1 ){
		cout << value << "  ";
	}

	// We can pass a STL vector or STL array as a regular C-ctyle array if necessary. 

	// Simply pass the address of the first element:

	func4(&myArray2[0]); // pass address of first element of the STL array
	func4(&myArray3[0]); // pass address of first element of the STL vector

	// or do the same using the data() member function

	func5(myArray2.data()); // pass address of first element of the STL array
	func5(myArray3.data()); // pass address of first element of the STL vector

	// The next 2 statements prove that & of the first element of an stl array or vector 
	//     is the same as the address returned by the data() member function

	cout << "\n\nAddress of first element in myArray2: " << &myArray2[0] << " and " << myArray2.data();
	cout << "\n\nAddress of first element in myArray3: " << &myArray3[0] << " and " << myArray3.data();

	cout << '\n' << std::endl;

	return 0;

}

// C-style arrays are converted to simply a pointer when passed to a function
void func1(int array[])
{
	// Note that the code below will not compile!
	// The begin() and end() functions and the range based for loop 
	//     will not work with array.  This is because array is just a
	//     pointer to int, and not an array of ints inside this function.

/*
	std::sort(std::begin(array),std::end(array));  // 2 errors here
												   // compiler does not understand std::begin(array) and std::end(array)
	cout << '\n';
	for ( auto value : array ){  // 1 error here - compiler cannot use range based for loop on a pointer
		cout << value << "  ";
	}
*/

//  But the following code, also commented out, would compile and work just fine.

/*
	std::sort(array,array+10); // using pointers as iterators

	cout << '\n';
	for ( int i = 0; i < 10 ; ++i ){
		cout << array[i] << "  ";
	}

*/

	cout << "\n\nsizeof C-style array with 10 int elements in func1 is: " << sizeof array;
}

// Function being passed an STL array of ints
void func2(std::array<int,10> & array)
{
	std::sort(array.begin(),array.end());
	// std::sort(begin(array), end(array)); // also works 

	cout << "\n\n";
	for ( auto value : array ){  
		cout << value << "  ";
	}

	cout << "\nsizeof STL array with 10 int elements in func2 is: " << sizeof array;
}

// Function being passed an STL vector of ints
void func3(std::vector<int> & array)
{
	std::sort(array.begin(), array.end());
	// std::sort(begin(array), end(array)); // also works 

	cout << "\n\n";
	for ( auto value : array ){ 
		cout << value << "  ";
	}

	cout << "\nsizeof STL vector with 10 int elements in func3 is: " << sizeof array;
}

// Simple function
void func4(int x[])
{
	cout << "\n\n The value of the 4th element is: " << x[3];
}

// Another simple function
void func5(int * const iPtr)
{
	cout << "\n\n The value of the 4th element is: " << iPtr[3];
}

// Again, note there is no real difference between func4() and func(5)