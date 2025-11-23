// Author: Bob Langelaan
// Date:   Jan 23, 2022

// More examples of passing containers by value and by reference

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <vector>

using std::cout;
using std::endl;

// Define some const values

const size_t NUM_ROWS = 5;
const size_t NUM_COLS = 4;

// Function prototypes

// Pass C-style array of dynamic size
void func1(int [], const size_t); 

// Pass stl array of size 10 by value
void func2(std::array<int,10>);  

// Pass stl array of size 10 by reference
void func3(std::array<int, 10> &); 

// Pass stl vector of dynamic size by value
void func4(std::vector<int>);   

// Pass stl vector of dynamic size by reference
void func5(std::vector<int> &); 

// Pass 2D C-style array with 4 columns and dynamic number of rows
void func6(int [][NUM_COLS], const size_t); 

// Pass 2D stl array with 4 columns and 5 rows by reference
void func7(std::array<std::array<int, NUM_COLS>, NUM_ROWS> &);

int main()
{

	//Create some arrays to pass to the 7 functions

	//First the 1D arrays

	int myArray1[10] = {10,1,9,2,8,3,7,4,6,5}; //C-style array

	std::array<int,10> myArray2 = {10,1,9,2,8,3,7,4,6,5}; // STL array

	std::vector<int> myArray3;
	// Copy contents of myArray1 into vector using push_back() function
	for (auto value : myArray1)
	{
		myArray3.push_back(value);
	}

	//Next the 2D arrays

	int myArray4[3][NUM_COLS] = { 0 }; // initialize to all 0's

	std::array<std::array<int, NUM_COLS>, NUM_ROWS> myArray5 = { 0 }; // initialize to all 0's

	// Invoke the 7 functions and output array passed afterward

	int counter = 1;

	// func1
	
	cout << "Invoke func" << counter++ <<" and then output array contents" << "\n\n";

	func1(myArray1, 10);  // 10 is passed to let function know 

	// Will be sorted because C-style arrays are always passed by reference
	for (auto value : myArray1)
	{
		cout << value << ' ';
	}

	// func2

	cout << "\n\nInvoke func" << counter++ << " and then output array contents" << "\n\n";

	func2(myArray2);

	// Will _NOT_ be sorted because passed by value
	for (auto value : myArray2)
	{
		cout << value << ' ';
	}

	// func3

	cout << "\n\nInvoke func" << counter++ << " and then output array contents" << "\n\n";

	func3(myArray2);

	// This time will be sorted because passed by reference
	for (auto value : myArray2)
	{
		cout << value << ' ';
	}

	// func4

	cout << "\n\nInvoke func" << counter++ << " and then output array contents" << "\n\n";

	func4(myArray3);

	// Will _NOT_ be sorted because passed by value
	for (auto value : myArray3)
	{
		cout << value << ' ';
	}

	// func5

	cout << "\n\nInvoke func" << counter++ << " and then output array contents" << "\n\n";

	func5(myArray3);

	// This time will be sorted because passed by reference
	for (auto value : myArray3)
	{
		cout << value << ' ';
	}

	// func6

	cout << "\n\nInvoke func" << counter++ << " and then output array contents" << "\n\n";

	func6(myArray4, 3);  // 3 is passed to let function know there are 3 rows

	// Will no longer be all 0's because C-style arrays are always passed by reference
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < NUM_COLS; ++col)
		{
			cout << std::setw(2) << myArray4[row][col] << ' ';
		}
		cout << '\n';
	}


	// func7

	cout << "\n\nInvoke func" << counter++ << " and then output array contents" << "\n\n";

	func7(myArray5);

	// Will no longer be all 0's because passed by reference
	for (const auto & rows : myArray5) { // iterate through all of the rows of myArray
		for (const auto & arrayValue : rows) { // iterate through all of the columns of myArray
			cout << std::setw(2) << arrayValue << ' ';
		}
		cout << '\n';
	}

	cout << "\n" << endl;

	system("pause");

	return 0;

}

// Pass C-style array of dynamic size
void func1(int myArray[], const size_t number_of_rows)
{
	std::sort(myArray, (myArray + number_of_rows)); // int * used as iterator
}

// Pass stl array of size 10 by value
void func2(std::array<int, 10> myArray)
{
	std::sort(myArray.begin(), myArray.end());
}

// Pass stl array of size 10 by reference
void func3(std::array<int, 10> & myArray)
{
	std::sort(myArray.begin(), myArray.end());
}

// Pass stl vector of dynamic size by value
void func4(std::vector<int> myArray)
{
	std::sort(myArray.begin(), myArray.end());
}

// Pass stl vector of dynamic size by reference
void func5(std::vector<int> & myArray)
{
	std::sort(myArray.begin(), myArray.end());
}

// Pass 2D C-style array with 4 columns and dynamic number of rows
void func6(int myArray[][NUM_COLS], const size_t number_of_rows)
{
	int value = 1;
	for (size_t row = 0; row < number_of_rows; ++row)
	{
		for (size_t col = 0; col < NUM_COLS; ++col)
		{
			myArray[row][col] = value++;
		}
	}
}

// Pass 2D stl array with 4 columns and 5 rows by reference
void func7(std::array<std::array<int, NUM_COLS>, NUM_ROWS> & myArray)
{
	int value = 1;
	for (auto & rows : myArray) { // iterate through all of the rows of myArray
		for (auto & arrayValue : rows) { // iterate through all of the columns of myArray
			arrayValue = value++;
		}
	}
}
