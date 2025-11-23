---
Created: 2024-06-12T18:40
Class: COMP2511
Reviewed: false
---
## Passing Arrays to Functions

- Recall that an array is just a pointer to the arrays 0th element
    - This means they are always passed by reference, rather than by value
    - This also means “array”, “&array[0]” and “&array” all have the same value
- Also keep in mind the & is the “Address-Of” operator
- 8 Hex = 32 bits
- 16 Hex = 64 bits
- Individual elements of an array are passed by value rather than reference
- To accept an array as an argument, you need to declare an array, and its often useful to get the length

```C
 int processArray(int arr[], size_t size)
```

- if you precede the array argument with const, the function treats the array as immutable

```C
int printArray(const int arr[], size_t size)
```

## Multidimensional Arrays

- When you pass a 2d array, you have to pass in the size of the 2nd array

```C
int sumArray(int arr[], size_t sz);
int summArray2(int arr[][4], size_t rowSize);
```

- You can initialize arrays within arrays

```C
int arr[2][2] = {{1, 2}, {3, 4}}
```