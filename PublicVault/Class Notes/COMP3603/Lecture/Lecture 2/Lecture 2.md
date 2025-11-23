# References
- Pass a reference by appending `&` to the argument type
```cpp
int passByValue(int);
int passByRef(int&);
```
- You can also create reference as a variable by
```cpp
int var = 20;
int& iRef = var;
```
- References must be initialized when defined
- Be wary of "Dangling References"
``` c++
int& func (int& iref)  
{  
    int x;//will be created on the stack_
    …  
    return x;  //returning a “dangling reference”  
}
```
- x is popped off the stack once the function completes, so the reference now points to an unmanaged memory location
- You can return references to a static local variable
	- This makes them not thread safe, though.
# Function Templates
- Basically a Java Generic
```cpp
template<typename T>
T maximum(T value1, T value2, T value3)
{
	T maximumValue{value1};
	if(value2 > maximumValue)
	{
		maximumValue = value2;
	}
	if(value3 > maximumValue)
	{
		maximumValue = value3;
	}
	return maximumValue
}
```
- Can only take a typename or built-in argument
- Should be included in the header file
- "The compiler writes the code for you using the template you provide"
	- It appends the written function or class to the end of the object file
# Container Classes
- Arrays are objects in cpp
```cpp
array<int, 10> myArray2{ 1,2,3,4,5,6,7,8,9,10 };
```
- Vectors are like java lists; they grow as needed.
	- Defaults to being empty, but can be initialized with values
	- Fixed number of bytes on the stack(16 bytes for 32-bit), pointer to an object on the Heap(Free Store in cpp)
```cpp
vector<int> myArray3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
```
# Range Based For Loops
- Like c-sharp and java; iterates through an entire structure
	- The variable used for iteration is a copy-by-value
```c++
array<int, 5> items{1, 2, 3, 4, 5};

// display items before modification
cout << "items before modification: ";
for (int item : items) {
   cout << item << " ";
}
```
- You can use a reference to modify the items
```cpp
 for (int& itemRef : items) {
    itemRef *= 2;
 }
```
- This doesn't work with a c-style array if you pass it to a function
	- The function doesn't know any of the metadata of the array; the function just knows it has a pointer to int.
# Auto
- Allows you to have the compiler figure out what the type should be
- Especially useful for range based loops and with Iterators
```cpp
// compiler figures out what type val should be
// const blocks changing the value of val
// so its like passing by value, but without the overhead
for (const auto& val : myArray) 
{
	cout << val << "  ";
}
cout << endl;

auto it = myArray2.cbegin(); // it is a const iterator of the type required, thanks to the auto keyword
for (; it != myArray2.cend(); ++it) // note that end() returns an iterator to element one position past the last element!
{
	cout << *it << "  "; //dereference the iterator to get the value
}
cout << endl;
//Especially useful for iterators, which have complex types
```
# Nested Arrays
```cpp
int NUM_COLS = 2;
int NUM_ROWS = 3;
std::array<std::array, NUM_COLS>, NUM_ROWS> myarray;
```
# Vectors
- Arrays that resize
	- A list, in most other languages
	- you can use `.push_back()` to add a new element to the end
	- can use `.resize()` to change the over-all size of the vector
- Don't use braced initialization; `vector<int> integers1{7};` creates a vector with 1 element - 7 - rather than a vector of length 7.
- Equality checks if the contents are equal
- You can copy a vector into a new vector with braced initialization
	- `vector<int> integers2{integers1};`
- C++ is not required to perform bounds checking when vector elements are access with square brackets`[]`
	- You can use the member function `.at()` to check the value at a position in the vector
	- Throws a `out_of_range` exception if out of bounds
- 