// Author: Bob Langelaan
// Date: Feb 10th, 2022

// Example of a class where a deep copy and deep assignment operator are required

// The rule of 3 states that if you need one of the following, you will likely need all three:
// 1) destructor 
// 2) copy ctor
// 3) overloaded copy assignment operator

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
private:
	int year, month, day;

public:
	// Default and conversion ctor
	Date(int yr = 2000, int mn = 1, int dy = 1)
		:year(yr), month(mn), day(dy) {}

	void display() const
	{
		cout << year << '/' << month << '/' << day << endl;
	}

	void setDate(int yr, int mn, int dy)
	{
		year = yr;
		month = mn;
		day = dy;
	}
};

class TimeAndDate
{
private:
	int hour, min, sec;
	Date* datePtr;

public:
	TimeAndDate(const Date & date = Date(), int hr = 0, int mn = 0, int sc = 0)
		:hour(hr), min(mn), sec(sc), datePtr(new Date(date))
	{
		//datePtr = new Date(date); // dynamically allocating a Date object for this class
								  //    using default copy ctor of the Date class
	}

	~TimeAndDate() // We need dtor because we dynamically allocate in the class ctors
	{
		delete datePtr;
		datePtr = nullptr;
	}

	// Copy ctor
	TimeAndDate(const TimeAndDate & copy)
	{
		hour = copy.hour;
		min = copy.min;
		sec = copy.sec;
		datePtr = new Date(*(copy.datePtr)); // We need to dynamically create a Date obj
											 //   Date default copy ctor used here
	}

	// overloaded assignment operator
	const TimeAndDate& operator = (const TimeAndDate& rhs)
	{
		if (&rhs != this) // test to avoid self-assignment
		{
			hour = rhs.hour;
			min = rhs.min;
			sec = rhs.sec;
			*datePtr = *(rhs.datePtr);  //shallow assignment is fine here
		}

		return *this;
	}

	void setDate(int yr, int mn, int dy)
	{
		datePtr->setDate(yr, mn, dy);  // We need to use Date setDate() method. Why not change directly?
	}

	void display() const
	{
		cout << setfill('0'); // changes the fill character from a ' ' to a '0'
		cout << setw(2) << hour << ':' << setw(2) << min << ':' << setw(2) << sec << "  ";
		datePtr->display(); // use display() method of the Date class
	}
};

int main()
{
	Date d(2022, 2, 10);
	TimeAndDate& t1 = *new TimeAndDate(d, 10, 20, 30); // Assign results of new operation to a reference

	TimeAndDate t2(t1);  // uses programmer defined copy ctor
	                     // t2 is created statically, while t1 waas created dynamically

	cout << "t1 = ";
	t1.display();
	cout << "t2 = ";
	t2.display();

	TimeAndDate* t3Ptr = new TimeAndDate();  // Assign results of new operation to a pointer
											// Uses default arguments
	cout << "\nt3 = ";
	t3Ptr->display();

	*t3Ptr = t1; // uses programmer defined assignment operator
	cout << "\nt3 = ";
	t3Ptr->display();

	// Change date in t1
	t1.setDate(2010, 12, 31); // We are updating t1 but it shouldn't update t2 or t3

	// Output the 3 TimeAndDate objects again
	cout << "\nt1 = ";
	t1.display();
	cout << "t2 = ";
	t2.display(); // Should be unchanged
	cout << "t3 = ";
	t3Ptr->display(); // Should be unchanged

	t2 = t2;

	// free up dynamically allocated memory
	delete& t1; // delete t1

	cout << "\nt2 = ";
	t2.display();  // we do not need to delete t2 because it was created on the stack and
	               // will be deleted automatically when it goes out of scope

	cout << "t3 = ";
	t3Ptr->display();
	delete t3Ptr; // delete object pointed to by t3Ptr
}