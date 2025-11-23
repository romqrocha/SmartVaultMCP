---
Class: COMP2522
Created: "[[2024 11 20]]"
tags:
  - OOP
  - DesignPattern
Reviewed: false
---
- When Java sees a class variable, it assigns a memory address for the call using the lookup table.
- ARC - automatic Reference Counting
	- Garbage collects when there are no references to the object so the memory can be freed
1) Don't allow any other class to call the constructor
	1) Can do this by making the constructor Private
2) Make a static method, getInstance(), that returns the object
3) Make a private static variable within the Singleton class of the class type
4) Inside getInstance, check if the static variable is null.
	1) If it is, construct it,
	2) if it isnt, return it.