---
Created: 2024-02-08T13:45
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - JavaScript
---
# JS Objects

javascript-arrays-and-objects/objects1.html

- declared with 
    
    ```JavaScript
    var object = new Object();
    ```
    
- In Java, Objects come from Classes.
- In JavaScript they’re different.
- **REALLY IMPORTANT:**

![[Three Laws of JS]]

## Arrays

javascript-arrays-and-objects/arrays1.html

- Basically just a box of stuff
- NOT associative! Only uses Array Indexes
- Can be declared with:
    
    - A constructor, or
    - A literal set.
    - Initialized with [ ]
    
    ```JavaScript
    let testArray = ["String", 1, 1.2, false];
    ```
    
- Arrays in JS are dynamic.
- Has built in methods:
    - push adds to the end
    - pop removes from the end
    - shift removes from the beginning
    - unshift adds to the beginning
- Can have mixed data types
- You can use indexes to update and item in the array
    
    ```JavaScript
    arr[10] = "spam";
    ```
    

# Var vs Let

- var is GLOBAL, not recommended
    - If you attempt to redefine a var already defined, it will throw an error.
- let is LOCAL, use as often as possible.
- You can also use “use strict” - HIGHLY RECOMMENDED, “ required.

  

## Functions

- Standalone; they don’t belong to a class
- Don’t have to specify a return type
- Arguments go in the header
- Because they are objects, they have properties
    - arguments within a function is an array of all the arguments