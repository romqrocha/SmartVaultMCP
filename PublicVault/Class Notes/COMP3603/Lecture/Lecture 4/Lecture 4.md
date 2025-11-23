# Lab 3
Complete the Inheritance exercise in the Exercise 1 folder of the "Lab 3 Start" folder.
You should look at the 3 C++ files in the folder and study the function calls in main().  
Note that some of the function calls will not compile because they do not obey the IS_A rule. 
You need to identify which of the function calls will not compile and for the remaining functions predict what will be output.  
Write your predictions into a text file that you will submit with your lab solution. 
When you have completed the exercise you will need to execute the code in the "Lab 3 Solution" folder to see if your predictions were correct.  
  
Note also the use of a forward declaration of the Derived class in the `Base.h` file.  This necessary because the Base class refers to the Derived class.  
  
- Exercise 12.11 from the text.  I have supplied a driver program in the "Lab 3 Start" folder.  All other files you need to start the exercise are in that folder as well.  Be sure to study carefully the driver program and make sure you understand it.
# Inheritance
- 
# Polymorphism
- 
## Under the hood
- 
# Run Time Type Identification (RTTI)
- `<typeinfo>` is associated with RTTI in C++
- Can compare types using `typeid()` to get a typeinfo object about a variable
	- You cannot assign a typeinfo object to a variable
	- can compare with == to check if they are the same type
		- Must be the EXACT same type; cannot be a derived class
# Casting
```cpp
//cast_type<targetType>(originalObject);
dynamic_cast<float>(someInt);
```
![[`static_cast`]]

![[`const_cast`]]

![[`dynamic_cast`]]

![[`reinterpret_cast`]]

## C-Style Cast and Function-Style Cast

C-style cast and function-style cast are casts using `(type)object` or `type(object)`, respectively, and are functionally equivalent. They are defined as the first of the following which succeeds:

- `const_cast`
- `static_cast` (though ignoring access restrictions)
- `static_cast` (see above), then `const_cast`
- `reinterpret_cast`
- `reinterpret_cast`, then `const_cast`

It can therefore be used as a replacement for other casts in some instances, but can be extremely dangerous because of the ability to devolve into a `reinterpret_cast`, and the latter should be preferred when explicit casting is needed, unless you are sure `static_cast` will succeed or `reinterpret_cast` will fail. Even then, consider the longer, more explicit option.

C-style casts also ignore access control when performing a `static_cast`, which means that they have the ability to perform an operation that no other cast can. This is mostly a kludge, though, and in my mind is just another reason to avoid C-style casts.

![[`bit_cast` - C++20]]
# Operator Overloading
```c++
//in header
const myClass& operator += (const myClass& rhs)
{
	...
	return *this;
}
```
alternatively
```c++
//in header
myClass &operator =(const myClass& rhs);
//in cpp
myClass& myClass::operator=(
   const myClass& rhs)
{
   ...
   return *this;
}
```
- We can add 2 objects of the same type now, yay!
- If we want to add others, we can use Conversion Constructors to convert to our object, or we can make an operator overload that takes the type we expect.
- Note: This only allows for `MyClass` to be the LHS operator(`myClass += 5` not `foo += myClass`)
	- We can enable this by overloading global methods
	```c++
	double& operator += (double & lhs, const MyClass & rhs)
	```
	- This means we may need to make this function a friend of `MyClass` so it can access the private members
- We **cannot** overload:
	- dot operator(`.`)
	- pointer to member(`.*`)
	- Scope operator( :::: )
- We cant change:
	- Precedence(Order of operations)
	- Associativity(Left-to-right or right-to-left)
	- Arity(number of operands)
	- How operators work of fundamental types
		- This means at least one of the operands must be a user-defined type
- Because we need the object to be the left-hand object, we need to offer friendship if we want to use 
# Dynamic Memory Allocation
- the `new` keyword allows us to allocate objects and primitives on the heap rather than the stack
	- `new` returns a pointer, not a reference.
- This means we need to use `delete` to free the memory
	- It is good practice to assign the pointer to `nullptr` after deleting
		- this is because calling delete after deleting a pointer can corrupt the heap
- When deleting a c-style array, we need to include `[]`.
	- Otherwise, only the first element is removed; remember **Array names are pointers**.
```c++
int* myArr = new int[10];
delete [] myArr;
myArr = nullptr;
```
# Copying
- C++ compilers will automatically create a shallow copy constructor for objects
## Shallow Copy
- Copies each value directly
- This means sub-objects **pointers** are copied, rather than the values.
	- This means if the memory for either object is freed, we now break the other object.
## Member-Wise Copy
- 