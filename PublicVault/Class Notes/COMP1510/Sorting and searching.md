---
Created: 2024-04-08T16:13
Class: Comp1510
Reviewed: false
tags:
  - Java
---
Sorting is the process of arranging items in a particular order

# Selection sort

- Strategy:
    - Select a value, put it in its final place(Smallest to first/largest to last), repeat
- Insertion and selection are similar in efficiency
- Approximately n^2 number of comparisons are made to sort list of size n
- so we can these sorts are _order n^2_
- Other sorts are more efficient: _order n log2 n_
- o(n) and o(n^2)
    - Since anything squared is going to dominate an equation, we ignore the rest of the calculation and just discuss the longest part
        - e.g.: if the calculation for time to sort something is 4N^2 -N + 5, N^2 is the thing that controls the length as soon as N gets past a small size.
- Selection sort performance
    - Total is 1 + 2 + 3 + … + (N-1) = N^2/2 - N/2
    - We ignore the /2, and can say this is an O(N^2) algorithm

## Insertion Sort

## Comparing

```Java
equals(Object other){
	return (other instanceof Contact 
		//We need to cast to Contact so the compiler knows we have the getter functions
		&& lastName.equals(((Contact) other).getLastName())
		&& firstName.equals(((Contact) other).getFirstName()));
```

Alternatively, we can compare hash codes.

```Java
public int hashCode(){
	//Use XOR operation to mix up the potential outputs and create more randomness
	return lastName.hashCode() ^ firstName.hashCode();
}
```

We can also use the comparable interface and implement compareTo();

  

## Searching

- The process of finding a target element within a group of items called the **search pool**
- Keep in mind the target may or may not be in the pool
- Two classic approaches:
    1. Linear
        - Starts at one end of a list and looks at each element
        - Eventually the target is found or the end is encountered
    2. Binary Search
        - Assumes the search pool is sorted
        - Examines the item in the middle first
            - keeps searching half on side that is closer to the target until its found
            - The remaining items in the pool are called the **viable candidates**
        - Like guessing in the middle when guessing a number between 1 and 100 until you find the number.