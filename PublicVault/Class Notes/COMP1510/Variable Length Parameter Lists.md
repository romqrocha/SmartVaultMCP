---
Created: 2024-04-04T12:09
Class: Comp1510
Reviewed: false
tags:
  - Java
---
- Allows us to pass in an arbitrary number of the same type of arguments

```Java
int average = findAverage(2, 3, 5);
int average2 = findAverage(1. 7, 4, 6, 99, 12, 2);
```

- We can use Method Overloading, but then we need 1 overload for each amount of array
- We can also use a Variable Length Parameter List

```Java
 //                 type      arrayName
public double average(int ... list)
```