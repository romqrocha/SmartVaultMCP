---
Created: 2024-01-11T11:35
Class: Comp1510
Reviewed: false
tags:
  - Java
---
- 4 language levels
    - Machine
    - Assembly
    - High-level
    - Fourth-generation
- Machine
    - Each CPU architecture, and even some OS’s, have their own specific _machine language_
    - can be written in hexadecimal
- Assembly
    - Machine code is assembly code with short words to describe, sort of pseudo functions?
- High-Level
- Fourth-generation
- A **Compiler** is a software tool that translates _source code_ into a specific target language - such as Intel machine code, or Apple Silicone code.
- Java works somewhat differently.
    - Java compiler translates Java source code into a special representation called _bytecode_.
        - **Bytecode** is not the machine language for any CPU
    - Bytecode is executed by the _Java Virtual Machine(_**_JVM)_**, which is a virtual PC that runs on your system
    - This makes Java ‘system agnostic’
    - The JVM will compile regularly piece of code into machine code to increase efficiency
- There are many programs that support the development of Java, such as:
    - Java Development Kit (JDK)
    - Eclipse
    - NetBeans
    - BlueJ
    - jGRASP
- Details vary, but the basic compilation and execution process is the same.
- Syntax and Semantics
    - _Syntax Rules_ of a language define how we can put together symbols, reserved words, and identifier to make a valid program
    - _Semantics_ of a program statement define what each statement means (its purpose or role within a program)
    - A program that is syntactically correct **may not** necessarily be logically correct
- Errors
    - Program can have 3 types of errors:
        - Compile-time
            - The compiler will find syntax and other basic errors and problems, and stop the creation of an executable
            - Usually due to incorrect syntax
            - If it doesn’t compile, its a compile-time error
        - Run-time
            - If it terminates suddenly, its a run-time error
        - logical errors
            - Runs to completion, gives unexpected or incorrect output

# Object Oriented Programming

- The purpose to writing a program is to solve a problem
    - To do this, we need to do the following:
        - Understand the problem
        - Design a solution
        - Consider the alternatives, maybe redefine the solution
        - Implement the solution
        - Test the solution
    - These are not linear, they will overlap and interact.
        - You may test, find it doesn’t work, redesign, test, consider an alternative, etc.
    - The key to designing a solution is to break it down into manageable pieces
        - When writing software, we design small pieces that are responsible for certain parts
        - An **Object Oriented Approach** lends itself to this kind of solution decomposition
        - We will dissect our solutions into pieces called ‘Objects’ and ‘Classes’
            - Classes are ‘object factories’, and what we write in code
            - an Object is a Class used in a program
## Object

   - All objects have:
        - States
            - A descriptive characteristic
                - Position, orientation, etc.
        - Behaviors
            - What it can do, or what can be done to it
                - Move, Rotate, etc.
        - A Bank Account object might have:
            - States:
                - Owner
                - Account Number
                - Balance
                - Type (Savings, chequing, investment)
            - Behaviors
                - Withdraw
                - Deposit
# Java Class
   - The definition/blueprint of an Object
    - Uses _Methods_ to define the behaviors of the object
    - The Class is the **concept** of an object, and the Object is the **embodiment** of that concept.