# Lab 4
------------ Exercise 9.5 from the text Part 1: 
I have put in the "Class Lab 4 Start" .zip file a folder titled “Exercise 9.5 Part 1 Start" which contains a MainProg.cpp file which you can use to test your solution.
There is also a "Sample Output.doc" file which will show what the output your solution generates should look like. This exercise does not actually involve overloading operators, while Part 2 below does.

----------- Exercise 9.5 Part2:  
Make changes to your Complex class solution for Part 1 above so that it will work with the MainProg_P2.cpp file in the folder "Exercise 9.5 Part 2 Start". 
What I am asking you to do is to overload the required operators. 
Overload the += , -= and == operators as member functions, and the remaining operators as inline global functions. 
The global functions you create in this exercise do _NOT_ need to be friend functions because they use the public member functions of the class whenever they need to access private member of the class, and therefore you should _NOT_ make them friend functions.

# Unary Operator Overloading
- Can be overloaded as
	- non-static member function with no arguments **or**
	- non-member function
```c++
//As non-static member function
class String
{
public:
	//overload the bang(NOT) operator
	bool operator!() const;
	...
};
// call with !s
// !s becomes s.operator!()

//as global function
bool operator!(const String &);
// !s becomes operator!(s)
```
# Binary Operator Overloading
- Can be overloaded as
	- non-static member function with one arguments **or**
	- non-member function(global) function with 2 arguments
```c++
//As non-static member function
class String
{
public:
	//this object appends another
	String operator+=( const String& ) const;
	...
};
// y += z becomes y.operator+=(z)

//first String is modified by appending the 2nd
//so the first cant be const
String operator+=( String &, const String &);
// y += z becomes operator+=(y, z)
```

## increment
```c++
// pre increment
Fraction& Fraction::operator ++()
{
    numerator += denominator;
    return* this;
}
// post increment
Fraction Fraction::operator ++(int) //note the "dummy" int
{
    Fraction temp = *this;
    numerator += denominator;
    return temp; // return original value
}
```