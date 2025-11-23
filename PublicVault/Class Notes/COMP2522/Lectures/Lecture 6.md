---
Class: COMP2522
Created: "[[2024 10 09]]"
tags:
  - OOP
Reviewed: false
---
# Generics
- Allows you to define a function that takes any type and returns the same, or a different, type
- We've seen it before! Any time we define a List we use generics
```java
List<T> name;
```
- Generics allow is to use any class in a class, and ensure the functions within are *generic* enough to handle all the use cases.
```java
class Box<T> //everywhere I use T in here, it'll be of the same type as the parent
{
	private T t;
	public void set(T t)
	{
		this.t=t;
	}
	public T get()
	{
		return this.t;
	}
}

class Main
{
	public static void main(final String[] args)
	{
		Box<String> stringBox = new Box();
		stringBox.set("Hello!") //no error!
		stringBox.set(1) //compiler throws an error, because I am trying to put an int in a box of String
	}
}
```
## Law of Demeter

- Also known as "Principle of Least Knowledge"
- Objects should only interact with its immediate dependencies
- An object should only call methods on
	1. Itself
	2. Its own fields/member variables
	3. Objects passed in as arguments to its methods
	4. Objects it creates locally inside its own methods
- An Object should not
	1. Call methods on internal object of other objects
		- Like talking to strangers
	2. Chain method calls across multiple objects
		- e.g. a.getB().getC().doSomething()
- Benefits:
	- Reduces coupling between classes
	- Easier to maintain
	- Improved readability
- We shouldn't assume or have to know about how a class implements its features to write out code - we should act as if we know only what the public methods are.
## Bounded types
- Creates restrictions of what types can go into a generic
```java
//We can safely use the + operator knowing we're only accepting things that extend Number in this function
public <T extends Number> void addNumbers(T a, T b) 
{  
	System.out.println(a.doubleValue() + b.doubleValue());  
}
```
### Wildcards
- Allow us to define a RANGE of types to use in a "generic"
	- ? = Unbounded Wildcard
		- Anything, or its children, or its parents
	- ? extends T = Upper-bounded wildcard
		- T or any subclass of T
	- ? super T = Lower-bounded wildcard
		- T or any superclass of T
- Unbounded is used mostly with lists, because we know we can accept a list of any type and use list-specific operations on it safely.
	- This also enforces type-safety because we've told the compiler we don't care about what type the list is, so we'll get an error if we try to add something to the list.
	- The only thing we know with unbounded wildcards is that we know its an Object.
	- Used when you want to take a generic action that would work on any object
- Upper-bounded
	- Must be a child of T, so we can depend on all methods that T has.
	- Used when we want to **access** something of type T
	- 
	```java
	public static void printPlaceInfo(final StorageBox<? extends Place> box)
	{
		final Place place;
		place = box.get();
		System.out.println(place.getName());
	}
	```
- Lower-Bounded
	- Ensures ? is a superclass of T, so we can put it inside any container that holds T or any superclass of T
	- Used when we want to **store** something of type T
	```java
	public static void storeCity(final StorageBox<? super City> box, final City city)
	{
		box.store(city);
	}	
	```

### Multiple Bounds
- You can have generics with multiple bounds
- First bound must be a Class or Interface
- Any additional bounds must be Interfaces
```java
//T must be comparable AND serializable
public <T extends Comparable<T> & Serializable> T getMax(T a, T b)
{
	return a.compareTo(b) ? a : b;
}
```

## PECS
- 
## Why don't we just use Object
- Need to cast the result of the return value of our Box class to turn it into the type we expect.
- Generics provide run-time type safety
```java
@FunctionalInterface
interface Timesable<T>
{
	//If we call with a double for T, we get a double out
	//If we call with a String, we get a String out, etc
	T times(T t, Integer i);
}

class Main
{
	public static void main(final String[] args)
	{
		Timesable<String> stringifier = (s, n)-> 
		{
			String output = "";
			for(int i = 0; i < n; i++)
			{
				output+=s;
			}
			return output;
		};
		
		Timesable<Integer> totalInBills = (bill, n)->
		{
			return Integer(bill * n);
		};
		//Notice how 1 function was used to handle and return two types of inputs?
	}
}
```
# Nested Classes
- Used when you only need the inner class to be used by the outer class
- If private or protected, then instances cannot be instantiated from outside the containing class
- If static, it can exist without the containing class
- if NOT static, it is called an inner class
- 4 types
	1. Static Nested
		- You don't need to make an instance of the outer class to create an instance of the static nested class
		- No access to outer class data
		- Use if you don't need access to the outer class data
	2. Non-Static Inner
	3. Local Inner
		- Defined inside a method
		- 
	4. Anonymous Inner
		- Good candidate to be replaced by a lambda expression or method reference
		- Were commonly used in event handling, threading, or small use-case scenarios where a full class declaration would be overkill
- Inner class can access the data and methods of the outer class, even if they're private
- Outer class can **indirectly** access methods and data of the inner class
	- Via an instance of that class
- Declaring a nested class is ugly as fuck
  ```
  outerClass.innerClass spam = new outerClass().new innerClass();
	``` 
- This should be avoided unless its absolutely beneficial 
- The most common place for it is GUIs
# Functional Interface
- A functional interface contains a single abstract method - AKA S.A.M(Single Abstract Method)
- May also contain default and static methods, but can only have **ONE** abstract method
- We can declare with the @FunctionalInterface annotation so the IDE will complain if you try to add additional stuff
- This also means we can not use the @Override full implementation and use a Lambda expression instead
- Because we have 1 abstract method, we know that the return type of a lambda we assign to a variable of the interface type because it MUST be the return type of that interface's abstract method

# Lambda Expression
- The implementation of a functional interface's single abstract method in a way that makes it:
	- Readable
	- Flexible
	- Short
- Similar to Anonymous functions from JS
- Exist without belonging to any class
- Reasons to use:
	- Can be passes as a parameter(Like an object!) to methods and executed on demand
	- Can write functional programming instead of/in addition to OOP
	- Readable, yet short
	- Effectively lets you redefine functions at runtime
	
## Syntax
```java
()->{}; // () needed if theres no parameters
x->{}; //() not needed if there is a single undefined parameter
(int x)->{}; //() needed if you define the TYPE of the single parameter
(x, y)->{}; // () needed for multiple parameters
x->code; //braces not needed if just one instruction and output of instruction matches return type.
```

## Examples
```java
interface Helloable
{
	void sayHello();
}

class Student
{
	void green(final Helloable h)
	{
		h.sayHello();
	}
}

class PoliceOfficer
{
	void shout(final Helloable h)
	{
		h.sayHello();
	}
}

class Main
{
	public static void main(final String[] args)
	{
		Student s = new Student();
		//Passing in a lambda
		s.greet(()->System.out.println("Hi!, I am a student!"));
		PoliceOfficer p = new PoliceOfficer();
		p.shout(()->{
			System.out.println("HEY!);
			for(int i = 0; i < 3; i++)
			{
				System.out.println("STOP!!!");
			}
		});
	}
}
```

- Iterable is a commonly-used functional interface that allows for a Lambda to be used inside foreach arguments
```java
import java.util.ArrayList;
import java.util.List;

class More
{
	public static void main(final String[] args)
	{
		List books;
		books = new ArrayList();
		books.add("power of now");
		books.add("can't hurt me");
		books.add("discipline equals freedom");
		books.add("meditations");
		//forEach takes a CONSUMER
		//A consumer takes 1 argument and returns nothing
		books.forEach(b-> System.out.println(b));
		books.forEach(book-> {
			if(book.title.length() < 10)
			{
				System.out.println(book);
			}
		});
	}
}
```

# Method Reference
- Sort of like a Lambda expression, but more reusable, since it points to an already existing method
```java
Class::methodName;
String::toUpperCase;
Book::Equals;
```
- This allows us to not write the implementation every time, and is generally preferrable.
- 4 types:
	1. Reference to Static method
	2. Reference to an instance method of an object of a certain type
	3. Reference to an instance method of an existing object
	4. Reference to a constructor
