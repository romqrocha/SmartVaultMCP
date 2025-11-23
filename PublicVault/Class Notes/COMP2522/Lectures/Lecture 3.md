---
Created: 2024-09-11
Class: COMP2522
Reviewed: false
tags:
  - Java
---
# Equals
- By default, compares the address in memory
- When you override equals, you also need to override the hashcode method
	- this is because equal objects must have equal hash codes
- This comes with a complex "Contract". It is:
	- *reflexive*
		- it should be equal to itself (x.equals(x) returns true)
	- *symmetric
		- x.equals(y) is true, then y.equals(x) will return true
	- *transitive*
		- if x.equals(y) is true, and y.equals(z) is also true, then x.equals(z) will also be true.
	- *consistent*
		- Multiple invocations of equals should consistently return true or false., provided no information is modified.
	- x.equals(null) should return false
# Hashcode
- returns an int
- Objects that are equal must have an equal hashcode
	- Unequal objects may or may not have an equal hashcode
- If the comparison is not an integer, you can use Objects.hashCode(comparison)

# Abstract
1) If you have one or more abstract methods, the class MUST be declared abstract
2) An abstract class cannot have objects made out of it - its just an idea
3) For a class to be concrete, all abstract methods in its lineage must have been implemented
- Generally, final and private do not mix well with abstract.
## Abstract class
- A conceptual class, but we don't want to make an object of it.
	- This means we can't have a class that is both Abstract and Final
- You can still use Polymorphism and substitution to assign a child class to an abstract class variable.
- You can call static methods off an abstract class

## Abstract Method
- Cannot have a body(So no curly braces)
- Abstract methods in a parent **must** be implemented by a concrete class
- Concrete classes cannot declare abstract methods

# Recursion
- Tail Recursion
	- Checks if it should continue recursion at the end
	- Calls recursion after the check
```java
public static int recMultiply(final int a, final int b){
	//a   b
	//3 x 5  = 3 + 3 + 3 + 3 + 3
	if(b == 0)
	{
		return 0;
	}
	return a + recMultiple(a, b - 1);
}
```
