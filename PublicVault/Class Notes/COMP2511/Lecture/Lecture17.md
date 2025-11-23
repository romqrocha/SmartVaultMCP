---
Created: 2024-07-22T18:47
Class: COMP2511
Reviewed: false
---
# Command line arguments

- pass arguments to main on Windows or UNIX

```C
int main( int argc, char *argv[])
```

- int argc = the number of arguments passed
- char * argv[] = an array of strings, where each pointer points to the beginning of each argument passes
    
    - argv[0] is always the name of the app
    
    ```C
    C:\myCopy input output
    ```
    
- argc = 3
- argv[0] = myCopy
- argv[1] = input
- argv[2] = output

  

# I/O Redirection

- The redirect symbol (<) can be used to get data from a program and put it into a file, or pass from a file into a program
    
    - Data flows from from open to close end
    
    ```C
    random.exe > out.txt
    ```
    
    - the output of random.exe gets written to out.txt
    - You can double up the redirect (<<) to **append** instead of overwriting
- Pipe command(|)
    
    - Output of one program becomes input of another
    
    ```C
    C:\random | sum
    ```
    
    - Output of random goes to sum

# Variable Length Argument List

- Functions with unspecified number of arguments
    
    - requires stdarg.h
    - use … as the last parameter
    - Requires at least 1 defined parameter
    
    ```C
    \#include <stdarg.h>
    
    double myFunc(int i, ...);
    ```
    
- When you use … it expands a bunch of macros that can be used within the function
    
    ![[vararg.c|vararg.c]]
    
    - va_list
        - Holds information needed by start/arg/end
    - va_start
        - initialized the object declared with va_list
    - va_arg
        - expands to an expression of the value and type of the next argument in the variable-length argument list
        - each invocation modifies the object declared with va_list so it points to the next object in the list
    - va_end
        - facilitates a normal return from a function whos variable-length argument list was referred to by the va_start macro

# Dynamic Memory Allocatio

## calloc

- can create dynamic arrays
    - Dynamic means _at runtime_
    - Static means _at compile time_

```C
void * calloc (nmembers, size);
```

- nmembers is the numbers of elements
- size of each element in bytes
- returns a pointer to a dynamic array(?)
- Clears the memory it allocates by setting all bits to zero
    - This slows down the function compared to malloc
    - is also usually not required

## Realloc

- Can dynamically resize arrays at runtime

```C
void * realloc(pntr, newSize);
```

- pntr is a pointer to the variable being reallocated
    - if NULL, works the same as malloc
- newSize is the new size of the variable in bytes
- returns a pointer to the reallocated memory
    - returns NULL if it cannot reallocate the memory
- Attempts to reallocate memory ‘in place’
    - compiler specific
- original contents will not be modified, unless newSize is _smaller_ than the original size
- if newSize is 0, its equivalent to calling free

  

# Constant Literal Suffix

- C has suffixes for constants
- u or U
    - unsigned int
- l or L
    - Long
- ul, lu, UL, LU
    - Unsigned Long
- f or F
    - float
- long double
    - l or L:
- If an int constant is not suffixed, it gets the type of the first type capable of storing it (int, long int, unsigned long int)
- unsuffixed floats are assigned double

# Function exit and atexit

- function exit forces a program to terminate
    - takes symbolic constant EXIT_SUCCESS or EXIT_FAILURE from stdlib.h
- atexit
    - takes a function argument
    - atexit does not terminate the program
    - generates a stack of functions, so the last one added is the first one called
    - called functions cannot take arguments or return values

# goto

- Unstructured programming
- used when performance is crucial
- Generally considered bad programming