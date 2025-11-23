---
Created: 2024-06-03T18:51
Class: COMP2511
Reviewed: false
---
- Functions in C are **independent** compared to Javas **member functions**
    - Since C has no classes, there are no member functions.
- A **parameter** is the definition of an argument that exists within the header of a function
- An **argument** is the data passed in to a function via the parameters
- C DOES NOT SUPPORT FUNCTION OVERLOADING
- A function header with no body is called a **function prototype**; it tells the compilers that a function with that signature exists **somewhere** and will be linked to later.
    
    - Contains a name, parameters, and return type
    
    ```C
    int square(int numbers); //function prototype
    												 //the label "number" for the argument is optional
    ```
    
- Arguments in C are **always** pass by value, not pass by reference.
- Functions must be prototyped or defined before main; if they are prototyped before main, they can be defined later.
- 3 ways to return control from a function:
    1. When a function that returns void reaches the closing brace
    2. return;
    3. return expression;
- C will automatically convert arguments will implicitly convert arguments to the appropriate type if possible; it will convert an int to a double, for example. You can lose accuracy due to this (if you convert a double to an int, for example).
    - This is called **Argument Coercion**
- Floating Point Types

|   |   |   |
|---|---|---|
|Data Type|printf Conversion Specification|scanf Conversion Specification|
|long double|%Lf|%Lf|
|double|%f|%lf|
|float|%f|%f|

  

Integral Types

|   |   |   |
|---|---|---|
|Data Type|printf Conversion Specification|scanf Conversion Specification|
|unsigned long long int|%llu|%llu|
|long long int|%lld|%lld|
|unsigned long int|%lu|%lu|
|long int|%ld|%ld|
|unsigned int|%u|%u|
|int|%d|%d|
|unsigned short|%hu|%hu|
|short|%hd|%hd|
|char|%c|%c|

- Each library has a **header** file that contains
    - function prototypes for all the functions in the library
    - definitions of various data types and constants needed by those functions
- custom library header files are \#include-d in “ “ rather than < >
- Random number generation can be achieved through

```C
\#include <stdlib.h> 
rand();
```

- Rand generates a value between 0 and RAND_MAX, which is the largest value your compiler will let you contain; at least 32,767
    
    - That’s usually way too large of a range
    - We can apply a **scaling factor** to rand() to reduce the potential values using modulo
    - we can also **shift** the value using addition
    
    ```C
    int die = rand() % 6 // values between 0 and 5
    int die2 = rand() % 6 + 1 //values between 1 and 6.
    ```
    
- Its comment to use srand() to seed the random number generator before you run rand() the first time using srand(time(0))
    - Be sure you dont set this within a loop; otherwise it will set the seed to the current time every iteration and return multiples of the same value.
- NULL is the same as 0.