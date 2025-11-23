---
Created: 2024-07-08T19:16
Class: COMP2511
Reviewed: false
---
# Unions

- Derived data type, like a struct, but all members share the same storage space
- Has members, like a struct, and members can be of any type
- Since all members share space, the unions must be at least as large as its largest member
    - This means you can only use one of the members at a time
- Defined the same as a struct

```C
union number {
	int x;
	double y;
};
```

- When initializing a union, you can give it a value that matches the first members type

```C
union number value = { 10 };
```