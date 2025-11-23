---
Created: 2024-06-10T18:46
Class: COMP2511
Reviewed: false
---
# Arrays

- the most basic of all types of containers
- not a class object, so there are no methods associated with it
    - this means there are no size/length functions/methods related to arrays
- An array is a group of elements of the same type, stored contiguously in memory
- You can create an array by using _name_ **type[size]**

```C
int arr[5]
```

- size_t is a data type used to control the length of an array
    - usually an unsigned int, but can sometimes be a short; depending on the system and the compiler.
    - cannot be negative
- When you access a specific index of an array, you calculate the memory address of the 0th element + index * sizeOfElement
- You can initialize array elements by placing values within { }

```C
int n[5] = {10} // initialize the first value to 10, the rest to 0.
int n[5] = {10, 20} // initialize the first to 10, the 2nd to 20, the rest to 0
```

- You can also specify the size of an array based on the initialized values if the size is left empty

```C
int n[] = {1, 2, 3, 4, 5}
```

- You can define the length with a **symbolic constant** using \#define in the header

```C
\#define SIZE 5
int arr[SIZE] = {0}
```

- This will effectively copy-paste the value of SIZE into everywhere SIZE is present, much like a const in other languages.

  

- C has no bounds checking, so we need to validate the input and index is within the array and of the correct value type

  

- Array of type char have unique features
    
    - Values do not need to be separated, or within braces, but can be if you want.
    
    ```C
    char string1[] = "first";
    char string2[] = {'f', 'i', 'r', 's', 't', '\0'};
    ```
    
    - An array of char always contains a null character ( \0 ) to signify the end; this means a string is always 1 character longer than the string you input.
- scanf does not check how large an array is
- scanf will read until a space, tab, newline, or end-of-file indicator is encountered
- An array name will give the same result as using a pointer to the array. Array names are pointers, which is an address.
- You can use static to a local array definition so the array doesnt need to be destroyed and recreated every time the function runs
    - static arrays are initialized to 0 at program startup
    - non-static arrays are stored on the stack, so they’re popped off once they are out of scope.