---
Created: 2024-09-11
Class: COMP2522
Reviewed: false
tags:
  - OOP
  - Java
---
# Inheritance
- In Java, all classes extend the Object class
- Taking the extra time and code to create lots of inheritance allows you to add new classes quickly and without repeated code.
- We can also use a parent class as a generic way to interact with core functionality
	- e.g. a Database class can handle being instanced with MySQL, Firebase, etc. - it doesn't care because they're all databases.
## Benefits
- Code and test reusability
- Extensibility
- Maintainability
- [[#Polymorphism]]
	- Enables objects of derived classes to be treated as instances of the parent
- Modularity

## Extends Keyword
```java
class Animal 
{
	public double weightKg;
	public Animal(final double weightKg)
	{
		this.weightKg = weightKg;
	}
}

class Dog extends Animal
{
	public Dog()
	{
		super();
	}
	...
}
```

## Final Class
A Final class cannot be extended
The String class, for example, is a final class and cannot be extended.

### Default constructor
- If you do not provide a constructor, Java will create one for you
- This is called the default constructor and takes zero arguments.
- The very first line in any constructor must be either super() or this()
	- super() calls the parent constructor

## Protected
- Protected limits access to
	- That class itself,
	- That class's child classes, anywhere, and
	- Any class in the same package
- Its not a good idea to make instance variables protected. Make getters and setters protected instead.

# Polymorphism
- Refers to the ability to treat objects of a different child through a common interface
	- The common interface is usually the parent class.
- Allows for flexibility at runtime since different objects can respond to the same method call in their own way
- This means a child class object can be used anywhere a parent class object is expected.
## Substitution
- A.K.A. [[Liskov Substitution Principle]]
- Allows for children to be used in place of their parents
	- e.g. a Biography inherits from Book, so you can use a Biography object anywhere a Book is required.
- This allows you to redefine parent behavior on a child, but be sure that the child has the behavior
	- e.g. a Dog and a Bat both inherit from Mammal. Dog.move() returns "run", Bat.move() returns "fly"
- If you want to check if an object inherits from a class, you can use 'instanceof'
```java
final Animal a1 = new Pitbull();
System.out.println(a1 instanceof Object); //always true for any object
System.out.println(a1 instanceof Animal);
System.out.println(a1 instanceof Dog);
```

## Casting
- You can cast from a child type to a parent type
- It is best practice to use instanceof before casting

## Overriding
- Overriding redefines a method that was already defined before in the hierarchy
- Must have same signature
- use @Override annotation
	- This ensures the signature matches an existing method - if you don't, the compiler will tell you
- Static and Private methods cannot be overridden
- Must have the same or wider visibility as the parent.

# Object Class
- Object class methods are available to absolutely all classes
- has methods that may be used in place of instanceof
	- getClass()
	- getName()
	- getSimpleName()

# Exception Handling
- Various categories
	- Checked
		- When things are likely to go wrong, and can be handled.
		- Forces other code to use try/catch
		- Forces thrower to declare it throws
		- Checked at compile time.
		- "Exception" is the root of checked exceptions
		- Most exceptions are checked
	- Unchecked
		- When things are unlikely to go wrong.
		- Does not force callers to check for this
		- "RuntimeException" is the root of unchecked exceptions
	- Custom
		- Use only when they add lots of readability and value
		- Generally stick to the normal Java Exception classes
## Custom Exceptions
```java
//Checked Exception
public class IllegalPinExpcetion extends Exception
{
	
}

//unchecked Exception
public class AnotherException extends RuntimeExtension {

}
```
# Try/Catch
- Used to handle exceptions, if you have checked exceptions
## Finally
- Always called, even if returning from a try/catch block
- Useful for resource management, such as closing a file
