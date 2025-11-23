You would have learned about these topics in the C course you took as a prerequisite to this course but it might be good to review it regardless:

================================================================================

I am going to explain below what a typedef is.  A typedef defines a type based on an existing type.  In other words a typedef is an alias for an existing type. Chapter 13, which covers the topic "Stream Input/Output", refers to typedefs.  For this reason, you should understand what typedefs are.

Typedefs are one of the features "inherited" from the C programming language.  But they can be very useful in C++ programming as well.  The steps to create and use a typedef are:

1) modify a definition so that it becomes a typedef.

2) use the typedef to define new objects/variables.

When you define the typedef, you position the name of the typedef where you would usually position the label if simply creating an entity.

Examples are likely the best way to understand typedefs, so here are a few examples:

Let's start with a simple example:

Without a typedef we might do the following:
```C++
int * iPtr1; // define a pointer of type int called iPtr1  
                // note that the label "iPtr1" is at the end of the statement

Now, let's create a typedef for "int *" and then use the typedef to create the a pointer exactly the same as iPtr1 like we did above.

typedef int * INT_PTR;  // creates the typedef INT_PTR  
                                    // note a typedef definition must begin with the keyword "typedef".  
                                    // note that the typedef name "INT_PTR" is at the end of the statement,  
                                    //     just as the label iPtr1 was at the end of the statement

INT_PTR iPtr1;             // defines the same pointer as before, only using the typedef created in the previous line of code
```
Here is a more realistic example. 
Without a typedef we might do the following:
```C++
Array<int,100> AI100_1, AI100_2;  // Use the Array template class from Assignment 4 to define 2 Array objects  
Array<double, 200> AD200;          //  Use the Array template class from Assignment 4 to define an Array object

Now, let's create typedefs for the 2 types of Array objects above and then use the typedefs to define the same 3 objects.  
  
typedef Array<int,100> AI100_def;  // creates first typedef  
typedef Array<double, 200> AD200_def;  // creates 2nd typedef

AI100_def AI100_1, AI100_2;  // use typedef to define 2 Array<int,100> objects.  
AI200_def AD200;                   // use typedef to define an Array<double, 200> object.
```

One last example to show that the name of the typedef being created will not always be at the end of the line of code that defines it.

We don't cover this topic officially because you would have been taught about function pointers when you learned C.  The type of function being referred to here is a global function, not a member function.  There is different syntax available in the C++ language for pointers to member functions.

So let's say we have the following function:  
  
`void myFunc(int, double); //function prototype`

We can define a pointer which may point to this function with the following code (note that the syntax is pretty ugly):

`void (* fPtr) (int, double);`

Note that fPtr, the function pointer being defined, is positioned midway through the line of code that defines the function pointer.  Further down when we define the typedef, we will need to position the name of the typedef in the same position.

Because function names are pointers themselves (much like array names are pointers) we can now do:

`fPtr = myFunc;  //fPtr now points to the function myFunc().
  
BTW, fPtr as defined above, may only be used to point to functions that have "int,double" as parameters and that return type "void".

Now, let's create a typedef and use it to define the same function pointer but using the typedef we have created instead:  
  
```c++
typedef void (* FUNC_PTR_I_D) (int, double);
// Note that the typedef created, "FUNC_PTR_I_D", is in not at the end of the line of code as in the previous examples.

FUNC_PTR_I_D fPtr; // define fPtr using the typedef we created in the previous line of code.  
  
fPtr = myFunc; //fPtr now points to the function myFunc() as before.
```
BTW, we can invoke the function using the function pointer fPtr in one of 2 ways:

1) `fPtr(10, 2.0);` //invoke the function that fPtr is pointing to with arguments 10 and 2.0.

2) `(*fptr) (10, 2.0);` //invoke the function that fPtr is pointing to with arguments 10 and 2.0.

The 2nd method is preferred because the 1st method could be confused with a normal function invocation.  This might cause someone to search for a function called fPtr which of course does not exist.

Also, we generally create function pointers so that we may pass a function as an argument to another function.  This is often referred to in C and C++ literature as providing "a call back function".