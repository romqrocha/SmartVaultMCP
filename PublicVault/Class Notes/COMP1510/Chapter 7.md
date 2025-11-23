---
Created: 2024-03-07T12:17
Class: Comp1510
Reviewed: false
tags:
  - Java
---
# Program Development

- Creation of software has 4 basic activities:
    1. Establishing the requirements
    2. Creating a design
    3. Implementing the code
    4. Testing the implementations
- Not strictly linear.

## Requirements

  

- Specify the tasks that a program **must** accomplish
    - _what_ to do, not _how_ to do it.

## Design

- Specifies _how_ a program will accomplish the requirements.
- Specifies how the solution can be broken down into manageable pieces, and what each piece will do.
- in OOP, determines what classes and objects are needed, and how they will interact.

## Testing

- Attempts to ensure the program will solve the problem under all the constraints

## Validating Parameters

- We need to ensure we handle incorrect input by handling it properly, such as _throwing_ an exception

## Handling Exceptional Cases

- Consider all possibilities for all possible combinations of the parameters
- If parameters are valid, process normally
    - includes things like processing a list of 0 length
- If parameters are invalid, throw an exception
    - _IllegalArgumentException_ indicates a method has been passed an illegal or inappropriate argument.
    - _throw new IllegalArgumentException(”error message”);_
- You can use try/catch to allow the program to continue if it hits an exception
- JUnit can handle exceptions, but requires a lambda expression

# Identifying Classes and Objects

- When looking at the requirements, Nouns will generally correspond to a class or object in the final solution, but are **possible** objects.

## Static

- Static means its associated with the **class** and not an object of the class.
- Memory for the static variable is allocated when the class is first referenced.
- All instances of a object with a Static variable share the memory location for that variable
    - If you change it in one, you change it for all of them.
- Static methods can reference other static methods and variables, but cannot reference non-static methods and variables within the class.

### Class Relationships

- Three most common relationships:
    1. Dependency: A _uses_ B
    2. Aggregation: A _has-a_ B
    3. Inheritance: A _is-a_ B
- Dependency is when one class needs another; usually by calling a variable or method of that the other.
- Sometimes a class is Dependent upon **itself**. String.concat takes another String object as a parameter, for example.

  

### Objects as Parameters

- The parameters in the function are a reference to the value passed in.
- This means if we pass in an object reference, we create an Alias, since object references point to a memory location.
- Therefore, any changes we make to the object is visible to all other Aliases