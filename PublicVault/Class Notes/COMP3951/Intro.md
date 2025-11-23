---
Class: COMP3951
tags:
  - classIntro
prof:
  name: Mirela Gutica
  email: Mirela_Gutica@bcit.ca
  hours:
    room: SW2 - 127
    day: Check course
grades:
  quizzes:
    percent: 10
    count: 7
  assignments:
    percent: 20
    count: 5
  midterm:
    percent: 25
    count: 1
  final:
    percent: 25
    count: 1
  project:
    percent: 25
    count: 1
---
# File naming convention
`(Lab/assignment)(number)_(name)_(class)`
- comment your code and include headers
- use /// for block comments (// for line comments)
- write robust and stylish code 
- include sources in headers, documentation and assignments
- do not copy and paste or use AI generated code
- use your own words
- **submit the whole project in a zip file**

# Namespace Doc
```
/// <summary>
/// Summary
/// Authors
/// Date
/// </summary>
```

# Framework Class Library
- Handles communication between itself and the device via the .Net Framework VM
- Supports:
	- The Core Functionality
	- Interacting with Databases
	- R/W XML, tabular, and structured data
	- Building thin client applications via rich server-side
	- building desktop-based applications with support for Windows GUI

# .NET
## VM
- FULLY Compiled to an Intermediate language
- At runtime, a JIT Compiler compiles the IL to the final executable form
## IL
- When compiled, contains the metadata for Interfaces, Properties, and Methods
- Similar to Assembly
	- stack-based
	- You can write code directly in IL
	- use ildasm is you want to look at the IL

## Common Language Runtime
- A runtime environment that manages the execution, such as JIT compiler and Garbage Collector
- Is portable on different platforms

### Common Language Infrastructure(CLI)
- Standardized by ISO and ECMA
- Is the standard that allows high-level languages to be used on different platforms without being rewritten for specific architectures

### Common Type System(CTS)
- Defines the rules that all times are declared, regardless of source language
- Defines a common set of types for use in different syntaxes
	- e.g. System.Int32 = a 4 byte integer
	- C# defines int as an alias of System.Int32
- Since CTS manages all types, and supports inheritance, CLR supports cross-language inheritance between managed languages.

# C-Sharp
## Design Goals
- Designed to be fully Object-Oriented and Component-Oriented
- Type-safe
- Automatic memory management
- direct stack allocation
- garbage collector
- However: 
	- Slow by comparison to C/C++
	- Garbage collector is slow and heavy

## Component-Oriented
- Coarser-grained than Objects
- can include multiple classes
- Often language independent

## #FC #definition Object Class
- Ultimate base class of all .NET classes.
- The root of the type hierarchy

## #FC #definition Component Class
- An independent, reusable, and self-contained unit
- Can be manipulated by .NET Classes and Objects
## #FC #definition Assembly
- The basic building block of .Net Framework Applications

## #FC #definition .NET Metadata
- In every EXE or DLL there is a complete description of the classes, methods, parameters, and data class members

## Garbage Collected System (GC)
- All memory allocation/deallocation is done by the GC
- Allocates a block of memory for new objects in the "Managed Heap"
	- Maintains a record of all references to this object
- Moves objects in the Managed Heap together to consolidate used and free space
- Requires ~1/1000th of the total processor time
	- Before it starts, all other managed threads are suspended
- It is possible to not use the GC
	- done when you declare a block of code as `unsafe`

### GC Generations
- The Managed heap is split into 3 smaller heaps, called Generations
- New objects are stored in generation 0
- Most objects are also reclaimed from generation 0
- Objects that survive collection are promoted and stored in generations 1 and 2
- Large Objects are created in a special generation part of the heap called the Large Object Heap(LOH)
- After performing collection on Generation 0, memory is compacted and promotes reachable objects to generation 1
- The time this all takes is non-deterministic

## Tips

- IDisposable pattern is used for telling an object when you are done with it
- When you create an object that handles unmanaged objects(file/window handles, network connections) you should provide the code to clean up the resources in a `public Dispose` method

## Unity
- Doesnt used .Net, uses Mono
- Scripts represent code in C#
- Code is compiled after every change
- 