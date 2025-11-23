---
Created: 2024-07-04T18:57
Class: COMP2511
Reviewed: false
---
- A **Struct** is a Aggregate Data Type
    - This means it can hold fields/members of different data types under a single name
- A Struct is defined using the _struct_ keyword

```C
struct card {
		char *face;
		char *suit;
	};
```

- Defining a struct does not create an instance of the struct; much like classes
- Structs also has no methods within it; all members must be public
- This means we have no encapsulation, inheritance or polymorphism

```C
struct time1 { //time1 is called the TAG
		int hour; //struct members
		int min;
		int sec;
};
```

- we can use sizeof to get the size of a struct; above would be 12 (4*3) bytes
- You can declare variables at the same time a struct is defined

```C
struct time2 {  //with tag time2
		int hour;
		int min;
		int sec;
} t1, tArr[10], * tPtr; 
//in this example we have created
// 11 instances of the struct time2 and a 
// pointer to a struct time2;
```

- You normally declare variables of the struct using the struct keyword, followed by the time and name of the variable

```C
struct time1 t2;
```

- You can also define values of a struct variable when you initialize it
- If you have less initializers than members, the remaining members are assigned 0/NULL

```C
struct time1 t2 = { 6, 24, 36 };
```

- You can create a struct without a tag, but if you don’t create instances when you define the struct, then it cant be created later.
- You can access variable members of a structs using dot notation

```C
t1.hour = 10;
t1.min = 59;
t1.sec = 20;
```

- To access members of a **pointer**, you use the **ARROW OPERATOR** (→)

```C
tPtr = &tArr[5];
tPtr->hour = 5;
tPtr->min = 12;
tPtr->sec = 50;
```

- You **CAN** dereference the pointer, then use the dot operator, but this is ugly and amateurish

```C
(*tPtr).hour = 15;
(*tPtr).min = 15;
(*tPtr).sec = 15;
```

- You can assign member values of 1 instance of a struct to another - this is Member Wise Assignment

```C
t1 = tArr[5];
// copies values of hour, min, and sec
// from tArr[5] to t1
```

- You cannot compare structs for equality, but you can compare fields
- You cant compare structs directly due to ‘holes’ in memory
    - specific data types can only be assigned at specific numbers(called words), so some structs may have garbage data within them

```C
if(t1 == tArr[5])...
//Not allowed!
```

- The only valid operations that may be performed on  
    structures are:  
    - assigning structure variables to structure variables of the same  
        type,  
        
    - taking the address (&) of a structure variable,
    - accessing the members of a structure variable (see  
        Section 10.4) and  
        
    - using the sizeof operator to determine the size of a structure  
        variable.  
        
- You cannot include fields that are the same type as the struct itself, but you **can** include a pointer of the same type

```C
struct employee2 {
		char firstName[ 20 ];
		char lastName[ 20 ];
		unsigned int age;
		char gender;
		double hourlySalary;
		struct employee2 person; // ERROR
		struct employee2 *ePtr; // pointer
}; // end struct employee2
```

- A struct containing a member that’s a pointer to the same structure type is called a **self-referential structure**
- defining a struct does not reserve space in memory, it just defines a new data type used to define variables

## Passing a Struct to a function

- structs are passed by value, same as any variable