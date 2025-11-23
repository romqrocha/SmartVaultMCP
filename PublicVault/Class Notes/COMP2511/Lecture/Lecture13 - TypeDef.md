---
Created: 2024-07-08T18:41
Class: COMP2511
Reviewed: false
---
# Typedef

- Allows you to define an alias for other data types
- to create a typedef, put typedef in front of a datatype and name

```C
typedef int* int_ptr_t;
int_ptr_t iPtr = NULL;
```

- This is commonly used to name structs

```C
typedef struct { //note that no tag is required
	int hour;
	int min;
	int sec;
} time_t;

typedef struct time1 Time1; 
//alternative way
//In this instance, the struct is named time1 and the typedef is Time1
```

- This allows you to not use struct when defining variables

```C
time_t Time2
//vs
struct time1 Time3;
```

- also useful for pointers to functions

```C
int func(int, double);
typedef int (*func_ptr_t) (int, double);
func_ptr_t funcPtr = func;
```