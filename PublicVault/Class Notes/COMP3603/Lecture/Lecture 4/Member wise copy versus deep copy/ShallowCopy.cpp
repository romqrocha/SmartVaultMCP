// Author: Bob Langelaan
// Date: Feb 10th, 2022

// Example of a class where shallow copy and shallow assignment suffices

#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
	int hour, min, sec;

public:
	Time(int hr = 0, int mn = 0, int sc = 0) // default and conversion ctor
		:hour(hr), min(mn), sec(sc) {}

	void display() const
	{
		cout << setfill('0'); // changes the fill character from a ' ' to a '0'
		cout << setw(2) << hour << ':' <<setw(2) << min << ':' << setw(2) << sec << endl;
	}
};

int main()
{
	Time & t1 = *new Time(10, 20, 30); // Assign results of new operation to a reference

	Time t2(t1);  // uses default Time copy ctor
	// Time t2 = t1; // identical to the previus statement - also invoked copy ctor
	cout << "t1 = ";
	t1.display();
	cout << "t2 = ";
	t2.display();

	Time * t3Ptr = new Time();  // Assign results of new operation to a pointer
								// Uses default arguments
	cout << "\nt3 = ";
	t3Ptr->display();

	*t3Ptr = t1; // uses default assignment operator
	cout << "\nt3 = ";
	t3Ptr->display();

	// free up dynamically allocated memory
	delete& t1;
	delete t3Ptr;
}