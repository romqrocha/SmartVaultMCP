---
Created: 2024-01-31T13:33
Class: Comp1510
Reviewed: false
tags:
  - Java
---
# Writing Classes

The bread and butter of Object Oriented Programming. **THIS IS THE MOST IMPORTANT CHAPTER**.

**TRUE** OOP is based on defining classes that represent objects with well-defined _characteristics_ and _functionality_

The class that contains **main** is the starting point of the program

- Class names should be PascalCase
- Name of class should be in **singular form**

## Class Definitions

- Data is declared at the top of the class
- Methods underneath
- Design your classes so they are _versatile_ and _reusable_
- Constructor is a public method named the same as the class, which handles instantiating the objects.

```JavaScript
public class Something {
	int size, weight;
	char category;

	public Something() { //Constructor for the class
	}
	
	public void methdod1(){
	
	}
	
	public void method2(){
	}
}
```

## Instance Data

### Scope

- the ‘scope’ of data is the area in a program where it can be referenced/used.
- Data declared at class level can be referenced by all methods in the class
    - this is called _instance data_
- Within a method can be referenced only within that method
    - This is called _local data_

## Encapsulation/Modifiers

- The most important aspect of OOP
- Two views of an object
    - Internal: The details of the variables and methods of the class
    - External: The services the object provides and how it interacts with the rest of the system
- From an **external** view, an object is an _encapsulated_ entity, and the entity provides specific services
    - These services define the _interface_ of the object.
    - e.g. The wall socket is an interface with the electrical system.
- You don’t **need** to know how everything around you works to use it.
- The thing doing the using is often called the **client**
- The thing being used is called the **service**
- The client can use the service, but shouldn’t need to be aware of how it works.
- Any changes to the objects state(its variables) should be made by the object.
- It should be difficult, but not impossible, to access the objects state directly.

### Visibility Modifiers

- Used to achieve encapsulation
- a _modifier_ is a reserved word that specifies characteristics of a method or data
- **final** defines constants, for example
- There are 3 visibility modifiers:
    - _public_
    - _protected_
    - _private_
    - The absence of a visibility modifier is technically a modifier as well - anything in the same package can see this.
- _protected_ is used with Inheritance.
- _public_ can be referenced anywhere
    - violate encapsulation because they allow clients to modify the data directly
    - constants remove this risk, because it allows a client to use it but not modify it - effectively making it an interface
- _private_ can only be referenced within that class
- Methods that provide services are declared with public visibility so it can be invoked by clients
- public methods are also called _Service Methods_
- a method created to help with a Service Method is called an _support method_, and should be private

## Method Declaration & Parameters

- Requires
    - An access level
        - public/private
    - a return type
        - All methods returning something other than void needs to have a return statement
    - a name
- Specifies the code that will be called when the method is called
- A method declaration begins with a _method header_
    - This contains the return type, the method name, and the parameter list
        - These parameters are called the _formal parameters_
- This is followed by the _method body_, which is where all the code happens
- When a method is called, the actual parameters in the invocation are copied into the formal parameters in the header

### Getter/Setters

- Getters and Setters need to start with ‘get’ or ‘set’
- We use Getters and Setters to control accessibility and make accessing variables **explicit**
- Getters are also called _accessors_
- Setters are also called _mutators_

## Constructors

- has the same name as the class
- has NO return type
- is NOT a method, though they have similarities
- Most common error is to put a return type on the Constructor
    - This turns it into a regular method

  

## Arcs and Images

## Events and Handlers

## Buttons and Text Fields

  

## UML

- Unified Modeling Language
- A diagram that represents data flow
- Box that represents a class - if the name is underlined, it represents an INSTANCE of that class
- 2nd section shows class variables I want to show, and their types
- 3rd section shows class methods I want to show, and the return types
- a dashed line shows relationships between classes