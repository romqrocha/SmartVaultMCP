---
Class: COMP2522
Created: "[[2024 09 25]]"
tags: 
Reviewed: false
---
# Interfaces
- Historically, A collection of public static final data and **abstract** methods
	- Can now contain "Default" concrete methods, too
	- To make a method in an interface, you **need** "default"
	```
	  default void someFunc(){};
	```
	- default methods can still be overwritten, but supply a default implementation for a method.
- Help implement "multiple inheritance"
- Declare at the level of the interface
	- e.g. Substitute an implementer class
- Functional Interfaces are important
	- For lambda expressions
	- for method references
- A functional interface has exactly ONE abstract method
- We can use Interfaces to create [[Collections]] of objects we know can do the same thing
- We can use an Interface to define the type of an object
- Everything inside an Interface is Public Static Final, even if its not listed as such.