---
Created: 2024-07-25T18:36
Class: COMP2511
Materials:
  - "[[createdata.c]]"
  - "[[createindex.c]]"
Reviewed: false
---
# Note for assignment

- Make sure you create and use the index file!!!!!!
- 2 of the files we look over today are more important than the others
    
    ![[createdata 1.c]]
    
    ![[createindex 1.c]]
    

# Function Pointers

- Contains the address of a function
- A function name is the starting address of code that defines the function
- Can be
    - Passed to functions
    - Stored in arrays
    - Assigned to other function pointers

## How to use

- Function pointers look like this:

```C
//returnType (*pointerName) (ParamType ParamName, ParamType2 ParamName 2)
int (*pfunction) (int first, int second);
//You can also create arrays of function pointers
int (*pfunc[5]) (int first, int second); // Array of 5 function pointers

pfunction = MyFunction; //note you dont need the address assignment
```

- We have to do this because if we **didnt** have the parentheses we would be defining 0a function that takes two ints and returns a pointer to int
- You can then use a function pointer in one of two ways

```C
//Way 1
printf("Results: %d", (*pfunction) (val1, val2));
//for arrays
printf("Results: %d", (*pfunc[2])(val1, val2));
//Way 2
printf("Results: %d", pfunction (val1, val2));
//for arrays
printf("Results: %d", pfunc[2](val1, val2));
```

- While both these work, way 1 is preferred because its obvious that you’re using a function POINTER rather than a function.

## Typedef

- To typedef a function pointer looks a little odd
    - The real catch is that the typedef name is where the function pointer name would usually be

```C
typedef int(*FUNC_PTR) (int first, int second);
FUNC_PTR pfunction2;
```

## Example: qsort

- qsort, short for Quick Sort, is in stdlib.h
- takes a function pointer that has the following signature
    
    ```C
    int (*funcName) (const void *left, const void *right)
    ```
    
    - qsort passes two values from whatever you’re trying to sort and passes them to the given function
        - If negative, its in correct order
        - if positive, its in incorrect order
        - if 0, they’re equal
    - qsort will shift the bytes based on the return values of your function to make the given array sorted

# Index File

- Allow us to bring much smaller amounts of data from data files into memory when trying to sort and interact with them.
- Requires 2 data structures
    1. Index Header
        - Contains metadata about data and index files
        - Metadata holds the ID, Key Data, Record Count, and other data.
    2. Index records
        - Contains key(The field on which we sorted) and file position of each data record
- To create index file:
    
    1. Create index array in memory
    2. Populate Index Array from Data File scan
    3. Sort array on Index Key using qsort
    4. Write the index file to disk _**in binary mode**_
    
    ![[C_IndexFileExample.png|C_IndexFileExample.png]]
    
- To use an index file
    1. Open Data and Index files for reading
    2. Read the index header in Index file
    3. Analyze Header Data for compatibility
    4. Read each index record in Index file
    5. Seek Data record in Data File based on File Position in Index Record
    6. Read and Output Data Record