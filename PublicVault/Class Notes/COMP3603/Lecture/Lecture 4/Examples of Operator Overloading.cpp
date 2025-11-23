// Introduction to operator overloading
// Author: Bob Langelaan
// Date: Sept. 5th, 2023

#include <iostream>
using namespace std;

class BigInt
{
	// BigInt class is offering friendship to the 2 global functions that 
	//    overload the << and >> operators
	friend ostream& operator << (ostream& out, const BigInt& bi);
	friend istream& operator >> (istream& in, BigInt& bi);

private:
	long long value;

public:
	// The following is both a default ctor and also a conversion ctor
	explicit BigInt(const long long & v = 0)
		: value(v) // Member Initializer List (MIL)
	{
		//value = v; // Not necessary because of MIL above
	}

	// Overload the += operator
	const BigInt& operator += (const BigInt& rhs)
	{
		value += rhs.value;
		return *this;
	}

	// Overload the pre-increment operator
	BigInt& operator ++ ()
	{
		++value;
		return *this;
	}

	// Overload the post-increment operator
	BigInt operator ++ (int)
	{
		BigInt temp = *this;
		++value;
		return temp;
	}

	// Overload the pre-decrement operator
	BigInt& operator -- ()
	{
		--value;
		return *this;
	}

	// Overload the post-decrement operator
	BigInt operator -- (int)
	{
		BigInt temp = *this;
		--value;
		return temp;
	}

	// Overloads the * (multiplication) operator
	// if for example:
	// a = b * c;
	// b and c should not be modified which is why you see that
	//    both the member function and the parameter are const.
	BigInt operator * (const BigInt& rhs) const
	{
		BigInt temp;
		temp.value = value * rhs.value;
		return temp;
	}

};

int main()
{
	BigInt a, b(10);

	//a = 20; // will not compile because implicit conversion is not allowed
	a = BigInt(20); // explicit conversion required

	a += b; // requires += operator to be overloaded
	cout << "a = " << a << endl; // requires << operator to be overloaded

	cout << "\nEnter values for a and b: ";
	cin >> a >> b;
	cout << "a = " << a << ", b = " << b << endl;

	a = BigInt(5);
	cout << endl;
	cout << ++a << endl; // 6 
	cout << a++ << endl; // 6
	cout << a << endl << endl; // 7

	cout << a-- << endl; // 7
	cout << --a << endl; // 5
	cout << a << endl; // 5

	cout << "\nEnter value for b: ";
	cin >> b;

	cout << "a * b = " << a * b << endl;

}

// overload << operator
// object on the left of operator is an ostream object
//    so must be overloaded as a non-member (global) function.
ostream& operator << (ostream& out, const BigInt& bi)
{
	out << bi.value; //requires friendship from the BigInt class
	return out;
}

// overload >> operator
// object on the left of operator is an istream object
//    so must be overloaded as a non-member (global) function.
istream& operator >> (istream & in,BigInt& bi)
{
	in >> bi.value; //requires friendship from the BigInt class
	return in;
}