---
Created: 2024-06-06T18:36
Class: COMP2511
Reviewed: false
---
# Enums:

```C
enum Names { Value1, Value2, Value3...};
//Int value  0        1       2   ...
```

- Common for Values to be in CONSTANT CASE, since they’re constant values
- To use a value from an enum, you declare the enum as the type of the variable

```C
enun Names name = Value2;
```

- You cannot select the values of an enum by ordinal

  

# Storage Classes

- Attributes of variables include:
    
    - Name
    - Type
    - size
    - value
    
    ```C
    int bob = 4;
    //name is bob
    //type is int
    //size is 4 bytes
    //value is 4
    ```
    
- Each identifier also has Storage Class, Storage Duration, Scope, and Linkage
- C has the **Storage Class Specifiers**
    - auto
        - Stored on the stack
        - Popped off the stack when it goes out of scope
        - the default value, so you don’t need to use it.
    - register
        - Store this in the register, so it can be accessed faster
        - Compilers figure this out automatically, so we don’t really need to use it.
    - extern
        - value is stored in some external input
        - Not going to be using it in this course.
    - static
- A **Storage Class** determines _duration, scope,_ and _linkage_
- **Storage Duration** is the period during which an identifier exists in memory. When the duration has expired, the identifier is popped off the stack.
- **Scope** determines where a program can reference it.
    - Function
        - within an entire function
    - File
        - within an entire file, is declared at the top of a file.
    - Block
        - within a code block ( within { } )
    - Function-prototype
        - basically just the prototype header; you can have 2 variables named the same between 2 prototypes, but not within the same prototype.
- **Linkage** is if the identifier is known only in the current file or if it able to be known in any other source file the properly declares it.

  

# Memory areas

- The stack
    - automatic variables
- Static Data area
    - global variables and static local variables
        - static variables declared within a function retain their values between function calls
- Heap
    - dynamically allocated variables; created by malloc(), calloc() and realloc()
    - anything created with New
        - When there are 0 references to an object on the stack, garbage collection frees up the memory.