---
Created: 2024-07-29T18:40
Class: COMP2511
Reviewed: false
---
# C Preprocessor

- Preprocessing occurs before a program is compiled
- Allows for:
    - The inclusion of other files
    - Definition of symbolic constants and macros
    - Conditional compilation of program code
    - conditional execution of preprocessor directives
- Preprocessor directives(instructions) begin with #
- You can only have whitespace before the #

![[C_Build_Process.png|C_Build_Process.png]]

## \#include

- Copy the content of the given file in place of the directive
- \#include <filename>
    - searches the c standard library for the file
    - should be used for c standard library files
- \#include “filename”
    - Searches the current directory for the file, then searches the standard library if a file is not found
    - Should be used for user-defined files

## \#define

- Used to create symbolic constants and macros
- symbolic constant
    
    - Symbolic constants replaces all occurrences of the symbolic constant with the replacement text when compiled
    
    ```C
    //constant format
    \#define identifier replacement-text
    
    //how to use
    \#define PI 3.14159
    
    float x = PI;
    ```
    
    - pre-processor does not check that its supply the correct input type; for example, an int instead of a float.
- Macro
    
    - Operation defined in \#define
    - A macro without arguments is treated like a symbolic constant
    - Keep in mind pre-processing is just text insertion - _THERE IS NO TYPE CHECKING_
    
    ```C
    //the macro
    \#define CIRCLE_AREA( X ) ( PI * ( X ) * ( X ) )
    //will cause
    float area = CIRCLE_AREA( 4 );
    //to expand to
    area = ( 3.14159 * ( 4 ) * ( 4 ) )
    ```
    
    - Its important to surround arguments for a macro with parenthesis for expansion
    - without them, something like the following could happen
    
    ```C
    \#define CIRCLE_AREA ( X ) PI * X * X
    area = CIRCLE_AREA ( c + 2 )
    area = PI * c + 2 * c + 2
    ```
    
    - You can also have multiple arguments
    
    ```C
    \#define RECTANGLE_AREA( x, y ) ( ( x ) * ( y ) )
    ```
    

## \#undef

- Undefines a symbolic constant or macro
- If undefined, it can be redefined later

## Continuation character

- Place a \ at the end of a lune to continue on another line in a macro

  

## Conditional Compilation

- cast expression, sizeof, enumeration constants cannot be evaluated in preprocessor directives
- Syntax is similar to _if_

```C
\#if !defined ( NULL )
	\#defne NULL 0
\#endif
```

- There must be a endif for every if
- Common abbreviations:
    - \#ifdef is short for \#if defined (name)
    - \#ifndef is short for if !defined (name)
- Especially useful for debugging

```C
\#define DEBUG
\#ifdef DEBUG
	printf("variable x = %d\n", x);
\#endif
//Now we can comment out \#define DEBUG if we dont want to print debug text
```

- A common use is for an “include guard”
- You set up a symbolic constant that is the file name, then multiple imports of your file won’t cause multiple definitions of the same functions or variables
- using the file name is useful because its unlikely someone will have 2 files of the same name in their program

```C
//filename is func.h
\#ifndef FUNC_H
	\#define FUNC_H
	int cube(int input);
\#endif
```

# Multiple Source File Programs

- Function definition must in one file, and cannot be split up
- global variables are accessible to functions in the same file
    - This means they must be defined in every file in which they are used
    - e.g. to use _int flag_ from file a in file b
        - extern int flag;
- The keyword _static_ specifies that the variables can only be used in the file in which they are defined
- It is possible to recompile only the changed files
    - The process for this varies based on the system

# Storage Classes

![[C_Scope_Declarations.png|C_Scope_Declarations.png]]

## Automatic

- declared within a block, and can only be used within that block
    - auto keyword is option, and usually not used

## Register

- Use to be used to tell the compiler to store a value in register
- Now, compilers are far smarter, so dont even bother trying :)

## Static

- All static variables persist for duration of the program

### Static (none) - aka static local

- defined in a block with keyword static
- no linkage possible

### Static (internal)

- Use the static keyword with global variable
    - limits scope to this file

### Static (extern)

- A global variable with the _extern_ keyword
- allows it to be defined and called in other files