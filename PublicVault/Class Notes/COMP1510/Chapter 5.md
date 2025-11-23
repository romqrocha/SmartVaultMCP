---
Created: 2024-02-07T13:31
Class: Comp1510
Reviewed: false
tags:
  - Java
---
# Conditionals and Loops

## Flow of Control

- Default is linear - the order is top-to-bottom, one after the other.
- A _Conditional Statement_ lets us choose which will be executed next.
- Basic statements are:
    - If
    - If-Else
    - Switch

## Boolean Expressions

- Java usually uses _equality operators_ or _relational operators_,which return Boolean results
    - == equal to
    - != not equal to
    - < less than
    - > greater than
    - <= less than or equal to
    - >= greater than or equal to
- There are also _logical operators_
    - ! Logical NOT
    - && Logical AND
    - || Logical OR
    - They take boolean operands and output boolean results

### Order of Operations

- ! has higher priority than && or ||
- && has higher priority than ||

### Short Circuit

- If A in && is false, it doesn’t check B
- if A in || is true, it doesn’t check B

## IF

```Java
if (sum > MAX)
	delta = sum - MAX;
```

## IF ELSE

```Java
if ( condition )
	statement1;
else
	statement2;
```

## AND

  

### Comparing Strings

- called a Lexicographic ordering
- When comparing 2 strings, you either get 0, a positive number, or a negative number.
    - If 0, they’re the same
    - if positive, string 1 is larger than string 2
    - if negative, string 1 is smaller than string 2
- should use String.compareTo();
- Shorter strings come ‘before’ longer strings

### == with objects

- ==, when comparing two objects, returns true if they’re an alias of each other.
- Doesn’t look if they have the same content.
- You can redefine this with the equals method in a class.

  

# Loops

- formally called Repetition Statements
- Controlled by boolean expressions
- Java has 3 kinds; while, do, and for.
    - Use a while loop when you don’t know how many times you need to do something
        
        ```Java
        while (condition) {
        	statement;
        }
        ```
        
        - if a while loop is false when initialized, its never executed.
        - if a condition never becomes false, it will make an _infinite loop_ until a user interrupts it.
            - Usually a logical error.
    - use a for loop when you know how many times you need to do something
        
        ```Java
        for (int i; i > n; i++){
        	System.out.println(i);
        }
        ```
        
- A **Sentinel Value** can be used to maintain a running sum
    
    - Sentinel Values are special input value that represents the end of input
    - e.g. “type X to quit”
    
      
    

## Input Validation

- Generally good to validate the input when possible

## Iterator

- An Iterator has a _hasNext_ method that returns true if there is at least one more item to process
- Scanner is an iterator for reading input
- Scanner can also be used to read a file
    - requires the **java.io.File** class
- Eclipse uses the root folder of the project as the working directory
- Scanner has a useDelimiter method that takes a regex to change the default delimiter

## Array List

- Object that stores a list of objects
- part of java.util package
- can reference items in the array using a _numeric index_
- grows and shrinks as needed
- Arrays are declared to hold a specific type of object
    
    - You **can** do it without declaring the type, but it makes it hard to know what’s inside the array
    
    ```Java
    ArrayList<String> names = new ArrayList<String>();
    ```
    
- Useful methods
    - boolean add(E obj)
    - void add(int index, E obj)
    - Object remove(int index)
    - Object get(int index)
    - boolean isEmpty()
    - int size()
- Arrays make use of _generics_, which offer extra type checking at compile time.