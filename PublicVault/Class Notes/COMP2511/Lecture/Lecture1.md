---
Created: 2024-05-27T19:39
Class: COMP2511
Reviewed: false
---
- C is low-level, so for each C statement there is a lot less machine language statements compared to other languages
- Embedded systems are processors that are built in to the hardware; programmable thermostats for example
- C is procedural; so there are no classes. Its just functions.
    - No inheritance, polymorphism, or encapsulation
- The two parts of learning C are learning the syntax and learning how to find and use functions within the C standard library.
- C programs go through 6 phases to be executed
    1. Edit
        1. Writing the code itself
    2. preprocess
        1. Preprocessors runs code and functions for you
        2. Runs the preprocessor commands you’ve embedded to expand your code. Like imports!
    3. compile
        1. makes the code into something your processor understands
        2. Turns it into a .obj file
    4. link
        1. Puts the code into an exe, and connects all the function names and object code together.
        2. 2 types of errors you’ll get at this stage;
            1. When the Linker cant find a function
            2. When the Linker finds multiple functions of the same name.
    5. load
        1. Loads it into memory
        2. The loader needs to know where the memory is so it can change some code based the **absolute memory values** it needs rather than **relative memory values**
    6. execute
        1. Runs the code

## Includes

```C
\#include <stdio.h> //C library include
\#include "myCode.h" //My .h file include
```

You do not include .c files; you only include .h files.

  

|Integral Type  <br>WHOLE NUMBERS|Size in Bytes|Floating Type|Size in Bytes|
|---|---|---|---|
|char|1|float|4|
|short|2|double|8|
|int|4|long double|8 or 16|
|long|4|||
|long long|8|||

## Writing a program

- **EVERY** C program must have a main function, which is where execution starts
- main is the only function that doesn’t need to return a value
- traditionally, main returns an int

```C
\#include <stdio.h>
// Single-line comments
/* 
	Multi-line comments
*/

int main(void) {
	int integer1 = 0;

	printf("Enter first integer");
	//the d tells the compiler 
	//we're expecting to read a integral argument
	//d for digit?
	scanf("%d", &integer1); 
	// & -> "the address" operator
	// We need to pass a reference to integer1 so we can write 
	// the inputted value to that location in memory

	printf("You entered %d\n", integer1);
	printf("Hello, world!\n");
}
```

- The C standard says an int must be equivalent to either a short or a long; for most PCs we use a long
- char is used for ASCII character
    - You can use it for small values, up to 255 unsigned
- Whitespace is ignored by the compiler
- printf is for output, scanf is for input