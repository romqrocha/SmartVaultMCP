---
Created: 2024-04-11T11:34
Class: Comp1510
Reviewed: false
tags:
  - Java
  - Review
---
- Only javadocs are useful
- _identifiers_ are the ‘words’ of a program
- Three types of errors
    - Compilers
    - Runtime
    - Logical
- The purpose of writing a program is to solve a problem
    - Understand
    - Design a solution
    - consider alternatives and refine solution
    - Implement
    - Test
- Objects
    - have
        - States
        - behaviors
    - Are defined by classes
- String Literal is when the user surrounds characters with “”

```Java
"This is a string literal"
```

- Eight primitive types
    - byte short int long
    - float double
    - boolean void
- Wrapper classes are object versions of the primitive values
    - Autoboxing is boxing and unboxing
    - This is the conversion of a Wrapper class to a primitive and vice-versa
- Narrowing conversion can lose information
- Widening wont
- Encapsulation is the idea that you shouldnt allow people to directly edit all attributes and call all functions within a class/object
- Block statements allows a series of statements to be controlled by a single logical comparison
- **USE IF WHEN YOU KNOW HOW MANY TIMES YOU’LL LOOP**
- **USE WHILE WHEN YOU DONT**

```Java
switch (expression ) {
	case value1:
		statement-list1;
		break;
	case value2:
		statement-list2;
		break;
	case default:
		statement-list-default;
		break;
}
```

- Code is not done until its tested.
- Classes that represent objects should have a singular noun name.
- Functions inside interfaces are declared but not defined within the interface
    - can specify static methods and default methods
- Actual parameter is the value of the thing passed to the formal parameters

  

- Variable length parameter lists creates a list of of the parameters given
    - the variable length parameter needs to be the last item in the formal arguments

```Java
public static void something(boolean correct, int... ints){
	for(int item: ints){
		...
	}
}
```