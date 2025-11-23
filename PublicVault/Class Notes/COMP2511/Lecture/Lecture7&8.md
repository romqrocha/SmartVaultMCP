---
Created: 2024-06-17T18:36
Class: COMP2511
Reviewed: false
---
# Pointers

- pointers are defined by placing an asterisk before the variable name

```C
int *iPtr = NULL;
```

- Pointers are usually initialized to NULL to avoid the garbage value used when uninitialized accidently referencing a place in memory currently used
- You can assign the address of another variable to a pointer variable with &

```C
int x = 10;
int *iPtr = NULL;
iPtr = &x;
```

- The pointer references the first byte of memory that holds x
- If you want to see the value a pointer points to, you can use the “indirection” operator

```C
display *iPtr;
```

TLDR

```C
&x // get address of x
*iPtr // get value stored at the memory location 
&iPtr // get address of the pointer, not the address the pointer is pointing to
*iPtr = 20 // assigns 20 to the memory location iPtr is pointing to
```

  

# Pointer Expressions & Arithmetic

```C
\#include <stdio.h>

int main()
{
    int arr[20] = {
        5, 10, 15, 20, 25,
        30, 35, 40, 45, 50,
        55, 60, 65, 70, 75,
        80, 85, 90, 95, 100
    };
    
    int * iPtr1 = &arr[0];
    // int * iPtr1 = arr // Same result as above!
    ++iPtr1;
    
    printf("%d\n", iPtr1[3]);
    //printf("%d", *(iPtr1 + 3)) // same result as above
    
    int * iPtr2 = &arr[5];
    //int * iPtr2 = arr + 5 // Same result as above
    
    *(iPtr2 + 2) = 100; // Sets the value of the 7th index to 100
    //iPtr2[2] = 100; // Same result as above
    printf("%d\n", iPtr2[2]);
    
    int result = iPtr2 - iPtr1;
    printf("%d\n", result);
}
```

# sizeof Operator

- sizeof returns the size of a variable, struct, or array
    - is applied at compile time, unless its operand is a **Variable Length Array** (VLA)
    - Returns the size as a size_t value in Bytes
    - It is **not** a function: Its an operator, like = or <