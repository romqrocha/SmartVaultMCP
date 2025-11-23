// Author: Bob Langelaan
// Date:   Jan 17, 2025

#include <iostream>
#include <array>

using std::cout;

// function prototypes
void printFunc(const int myArray[], const size_t size); // pass C-style array "myArray" of length "size"

template<size_t size>
void printFunc(const std::array<int,size> & myArray); // pass stl array of length "size"

int main()
{
	const size_t SIZE1 = 10;
	const size_t SIZE2 = 15;

	int myArray1[SIZE1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //C-style array
	int myArray2[SIZE2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 }; //C-style array

	std::array<int, SIZE1> myArray3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // STL array
	std::array<int, SIZE2> myArray4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 }; // STL array

	// Invoke with the 4 different arrays

	printFunc(myArray1,SIZE1);

	printFunc(myArray2, SIZE2);

	printFunc(myArray3);

	printFunc(myArray4);

	return 0;

}

// Pass C-style array to function with a second parameter that specifies size of array
void printFunc(const int array[], const size_t size)
{
	for ( size_t i = 0; i < size; ++i ){
		cout << array[i] << "  ";
	}

	cout << "\n\n";
}

// Pass STL array to template function
template <size_t size>
void printFunc(const std::array<int,size> & myArray)
{
	for ( auto value : myArray ){ 
		cout << value << "  ";
	}

	cout << "\n\n";
}