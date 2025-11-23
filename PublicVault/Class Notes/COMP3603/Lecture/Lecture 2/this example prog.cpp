// Author:  Bob Langelaan
// Date:    Jan 28, 2022

// The sample program below should compile and build without any errors,
//     though it will not produce any output.

//Declaration of Example class
class Example
{
public:

// Note that 3 Example objects will be passed to the Method1() member function.
//    One is the Example object that invokes the member function.
//    The other 2 are conventional parameters (one by reference, one by way of a pointer)
	Example & Method1( Example &, Example *);

private:
	void UtilityFunc(){;} // actually does nothing
	int i;
	double d;
};

// Our main program
int main(void)
{
	Example obj1, obj2, obj3, obj4;  // instantiate 4 objects of the Example class
	Example * oPtr = &obj1;  // declare pointer and have it point to obj1
	Example & oRef = obj1;   // declare reference and have it referece obj1

	// 3 ways to invoke Method1() with obj1
	// PLEASE NOTE: With each of the 3 invocations below, the "this" pointer of 
	//     Method1() will be pointing to obj1 upon entry to the method.

	obj4 = obj1.Method1(obj2, &obj3);  // using . operator and an object of the class
	obj4 = oRef.Method1(obj2, &obj3);  // using . operator and a reference to an object of the class
	obj4 = oPtr->Method1(obj2, &obj3);  // using -> operator and a pointer to an object of the class

	return 0;

} // End of main()

// Implementation of Method1
// Remember that the "this" pointer points to the object invoked with the method
Example & Example::Method1(Example & Eref, Example * Eptr)
{
	Eref.i = 10;  // assign the i member of the object that Eref references the value 10
	Eptr->i = 10; // assign the i member of the object that Eptr points to the value 10

	// These next 2 statements do exactly the same thing!
	i = 20;     // set the i member of the object invoked with Method1 to 20
	            //     using the "this" pointer implicitly
	this->i = 20;  // set the i member of the object invoked with Method1 to 20
	               //     using the "this" pointer explicitly

/*
	Note the similarity between the above 2 statements:

	Eptr->i = 10; 

	and

	this->i = 20;

	In both cases we are using a pointer to specify the object that
	the i data member belongs to.

*/

	// Realize that in the 4 invocations below, the compiler must somehow be
	//    told what object to invoke with UtilityFunc()
	Eref.UtilityFunc();    // invoke UtilityFunc() with object Eref references
	Eptr->UtilityFunc();    // invoke UtilityFunc() with object that Eptr points to

	// These next 2 statements do exactly the same thing!
	UtilityFunc();  // invoke UtilityFunc() with the object that the "this" 
	                //   pointer is pointing to (the "this" pointer is used implicitly)
	this->UtilityFunc(); // invoke UtilityFunc() with the object that the "this" 
	                     //   pointer is pointing to (the "this" pointer is used explicitly)

/*
	Note the similarity between the above 2 statements:

	Eptr->UtilityFunc();

	and

	this->UtilityFunc();

	In both cases we are using a pointer to specify the object that
	we want to invoke with UtilityFunc()

*/

	return *this;    // Will return the Example object that the "this" pointer is pointing to.
	                 // We are dereferencing the "this" pointer, which effectively references 
	                 //      the Example object that the "this" pointer is pointing to.
	                 // We return it by reference instead of by value to avoid making an extra  
	                 //    copy of the object (for efficiency reasons in other words).

}  // End of Method1()

// That's all folks!!!


