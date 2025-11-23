# Topics covered
Chapter 18 - Introduction to template classes and review of template functions  
- Chapter 18 slides: 4 to 12  
- Stack Class (make changes to a copy)  
	- Makes changes in the interface file and a few of the member functions. Rename Stack.cpp file.  
- Template Stack Class  
- Template Stack Class With Template Function  
- Template Stack Class with static members  
- Chapter 18 slides: 34 to the end  
- Introduction to Assignment 4
# Lab 5
**Part 1**: Use as your starting point for this part of the lab the files in the "Part1_Start" folder from the "Lab 5 Start.zip" . Convert the 3 global functions (_NOT_ the member functions) that are part of the solution into template functions. After being converted into template global functions (non-member functions), these functions can be used to overload their respective operators for potentially any class, not just the Complex class. If you do it correctly, you should not have to change the calls to these global functions in main(). The compiler will "implicitly" make use of the template functions you are providing it. You should recall that the full implementation of the global template functions need to be in a .h file, therefore you will need to remove the implementations from the .cpp file and add them to the end of the Complex interface file, where the function prototypes were before you converted these functions into templates functions.  
  
If necessary, refer back to the example program we looked at the beginning of Week 2 that introduced template functions.  
  
Compile and link the files after your changes to confirm that the application still works correctly.  
  
**Part 2**: Start with your solution for Part 1 above and convert the Complex class into a template class. The single parameter passed to the template will be used by the template to specify the type of the members that represent the real_part and imaginary_part attributes.  
  
IMPORTANT NOTE: Any member functions that return a type of "Complex", when converted into a template member function, must return a templatized Complex object, and not simply a Complex object. Alternatively, you can specify the return type at the end of the function header, known as a "trailing return type".  "trailing return type" is a language feature added in C++ 11. My solution to this lab shows an example of each. Ask me to explain further in class if unclear.  
  
**Part 3**: Exercise 18.3 of the text.
# Generics
- Function and class templates specify a variety of related(overloaded) functions(Called Function-template Specializations), or classes(Class-template specializations)
- This style is called "Generic Programming"
## Class Templates
```c++
template< typename T >
class Stack
{
	...
}
```
- See [[Class Notes/COMP3603/Lecture/Lecture 6/Template Stack Class/Stack.h|Stack Header File]]
- Typically defined in a header file
	- This means member functions are **also** defined in the header.
- If you want to have an interface file **and** definition file, you need to use a .h file rather than a .cpp file for the definition
	- See [[Class Notes/COMP3603/Lecture/Lecture 6/Template Stack Class With Template Function/Stack_inc.h|Stack_inc]] as an example of an example of a definition header.