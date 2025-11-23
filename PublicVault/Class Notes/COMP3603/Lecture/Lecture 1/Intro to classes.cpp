
// Author: Bob Langelaan
// Date: Sept. 14th, 2022

/*
// Part1 - This is C code
// Except that output is accomplished using C++ ostream object 'cout' and the '<<' insertion operator instead 
// using the C language printf() function

#include <iostream> // This is C++ library used for input and output
using namespace std; // This brings all the C++ libraries listed before this statement into scope

// Definition of a C language struct

struct Time
{
	int hour; // a public member
	int min;  // a public member
	int sec;  // a public member
};

int main()
{
	struct Time t1; // Create an instance of the struct Time - not initialized
	struct Time noon = { 12,0,0 }; // Create another instance of the struct Time - initialized this time
	struct Time DinnerTime = { 18,30,0 }; // Create another instance of the struct Time - initialized this time

	// Ouput the values assigned to the 3 members of the DinnerTime struct variable
	cout << "DinnerTime = " << DinnerTime.hour << ':' << DinnerTime.min << ':' << DinnerTime.sec << endl;

	t1 = DinnerTime;  // copies members of DinnerTime into corresponding member of t1
	                  // referred to a memberwise copy (or a shallow copy)

	// Ouput the values assigned to the 3 members of the t1 struct variable
	cout << "t1 = " << t1.hour << ':' << t1.min << ':' << t1.sec << endl;
}
*/

/*

// Part2 - Continuing evolution to a C++ solution 
// by adding public member functions and making data members private

#include <iostream>
using namespace std;

struct Time
{
public: 
    // Below is defined the member functions of the public interface of the struct Time
	// Below are defined 4 member functions that belong to the struct Time
	void setHour(int h)
	{
		hour = h;
	}

	void setMin(int m)
	{
		min = m;
	}

	void setSec(int s)
	{
		sec = s;
	}

	void display()
	{
		cout << hour << ':' << min << ':' << sec << endl;
	}

private: // This encapsulates the data members of the struct Time
	int hour; // private
	int min;  // private
	int sec;  // private
};

int main() // global function
{
	Time t1;  // notice that "struct" keyword no longer necessary

	//struct Time noon = { 12,0,0 }; // No longer allowed because the data members are now private
	
	// We can do the following instead:
	Time noon;
	noon.setHour(12);
	noon.setMin(0);
	noon.setSec(0);

	// struct Time DinnerTime = { 18,30,0 };//no longer allowed because data members are now private
	
	// We can do the following instead:
	Time DinnerTime;
	DinnerTime.setHour(18);
	DinnerTime.setMin(30);
	DinnerTime.setSec(0);

	//no longer allowed because data members are now private
	//cout << "DinnerTime = " << DinnerTime.hour << ':' << DinnerTime.min << ':' << DinnerTime.sec << endl;

	// We can do the following instead:
	cout << "DinnerTime = ";
	DinnerTime.display();

	t1 = DinnerTime;  //copies members of DinnerTime into corresponding member of t1

	//no longer allowed because data members are now private
	//cout << "t1 = " << t1.hour << ':' << t1.min << ':' << t1.sec << endl;

	// We can do the following instead:
	cout << "t1 = ";
	t1.display();
}

*/

// Part3 - Continuing evolution to a C++ solution
// struct is now called a class - no difference between the two other than members are public 
//    by default in a struct and private by default in a class.
// Added a class constructor
// Added getter member functions
// 4 of the member functions are defined as const member functions

#include <iostream>
#include <iomanip> // input/output manipulation - additonal formatting options of i/o
using namespace std;

class Time  // now we call it a class instead of a struct
{           // The only difference between the two is that members are by default public
	        //      in a struct and by default private in a class

public: // Below is defined the member functions of the public interface of the class

	// Below is the constructor of the class
	// The ctor's task is to initialize a object of the class
	// Constructors always have the same name as the class.
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	// Below are defined 3 member functions used to modify the data members of the class
	void setHour(int h)
	{
		if (h >= 0 && h <= 23)
		{
			hour = h;
		}
		else {
			cerr << "Invalid value passed to setHour() member function: " << h << endl;
		}
	}

	void setMin(int m)
	{
		if (m >= 0 && m <= 59)
		{
			min = m;
		}
		else {
			cerr << "Invalid value passed to setMin() member function: " << m << endl;
		}
	}

	void setSec(int s)
	{
		if (s >= 0 && s <= 59)
		{
			sec = s;
		}
		else {
			cerr << "Invalid value passed to setSec() member function: " << s << endl;
		}
	}

	// Below are 3 member functions to return values assigned to member data of the class
	// The next 4 member fuctions are const to safe guard against the functions changing values
	//     assigned to the data members of the object that invoked the member function
	int getHour() const
	{
		//min = 20;  // Not allowed because getHour() is a const member function
		//hour = 20;  // Not allowed because getHour() is a const member function
		return hour;
	}

	int getMin() const
	{
		return min;
	}

	int getSec() const
	{
		return sec;
	}

	void display() const
	{
		cout << setfill('0'); // sets the fill character to '0'
		cout << setw(2) << hour << ':' << setw(2) << min << ':' << setw(2) << sec << endl;
		cout << setfill(' '); // returns fill character to ' ', which is what it normally is.
	}

private: // This encapsulates the data members
	int hour;
	int min;
	int sec;
};

int main()
{
	Time t1(0,0,0);  // implicitly invokes the ctor of the class
	
	Time noon(12,0,0); //use ctor making 3 statements below uncessary
//	noon.setHour(12);
//	noon.setMin(0);
//	noon.setSec(0);
	
	Time DinnerTime(18,30,0); //use ctor making 3 statements below uncessary
//	DinnerTime.setHour(18);
//	DinnerTime.setMin(30);
//	DinnerTime.setSec(0);
	
	cout << "DinnerTime = ";
	DinnerTime.display();

	t1 = DinnerTime;  //copies members of DinnerTime into corresponding member of t1
	
	cout << "t1 = ";
	t1.display();

	// use getters to return values assigned to hour, min and second member of te noon Time object
	cout << "noon is equal to: " << noon.getHour() << ':' << noon.getMin() << ':' << noon.getSec() << endl;
}
