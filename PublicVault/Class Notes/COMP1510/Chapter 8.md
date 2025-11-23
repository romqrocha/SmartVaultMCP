---
Created: 2024-03-25T15:43
Class: Comp1510
Reviewed: false
tags:
  - Java
---
# Arrays

- Arrays are generally a list of things of the same size, and are stored next to each other in memory.
- Arrays are objects
- You can get an item of a specific index by putting the index within square brackets

```Java
arr[2]
```

- the **nth** value is at index n-1
- the things in an array are called the _array elements_
    - They all have to be of the same time - called the _element type_
    - Can be primitive or object reference.
- Arrays are declare by a type and square brackets
- when constructing the list, you declare how long your array is within the square brackets following new.

```Java
int[] arr = new int[10]
```