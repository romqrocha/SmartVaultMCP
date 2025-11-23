---
Class: COMP3760
Created: "[[2025 01 17]]"
tags:
  - 0a84ff/Algorithms
  - week/2
Reviewed: false
---
- Formulas can be organized by their most dominant term
- This is what Big-O notation is

# An algorithm for analyzing algorithms?  
• Given an algorithm (as input):  
	• Decide on the basic operation  
		• May require tie-breakers  
	• Count how many times the basic operation is executed  
		• Set up summations  
		• Simplify to an expression (function) that depends on N  
		• This is the running time  
	• Determine big-O class of the running time function
## Tie-Breaking for comparisons
1. Function calls (growing with N)  
2. Function calls (constant time)  
3. Key comparisons (comparing data)  
4. Assignments (copying data)  
5. Expression evaluations  
• Arithmetic tie-breakers:  
1. Multiplication/division  
2. Addition/subtraction  
• These are all more like guidelines than strict rules

# Algorithmic classes
- class: 1
	- Constant Time
- class: log n
	- Logarithmic
- class: n
	- Linear
- class n log n
	- n-log-n
- n^2
	- Quadratic
- n^3
	- Cubic
- 2^n
	- Exponential
- n!
	- Factorial

# Big-O
- A set of all functions whose rate of growth is the same as or lower then that of g(n)
- Execution will take **AT MOST** that long
- Most commonly discussed because we want to compare worst-case durations

# Big Omega
- Inverse of Big-O
- Means you dominate all the formulas under you
- Execution will take **AT LEAST** that long

# Big Theta
- Set of all functions that have the same rate of growth as g(n)
- The intersection of Big Omega and Big O
- Execution will take **THAT** long

### #fc #week/2  What does 'bigger' mean in terms of functions?
- Defined by the Big-O class

# Brute Force Algorithms
- Usually the straight-forward or simplest to implement
- Advantage
	- Easy to understand
	- easy to implement
	- Guaranteed to find a solution in a finite time
- Not usually feasible, except for small problem sizes
## Exhaustive Search
- Aka, "Generate and Test"
- Create all possible solutions
	- If only need one solution, stop when you find one
	- If you want the best, continue and compare

# Selection Sort
- 2 parts
	- Sorted
	- Unsorted
- Find the smallest, swap with element i
- Brute force because you need to check the entire array(minus the sorted section) to find the next smallest item

# Bubble Sort
- Sorted part and unsorted part
- largest found value will continue to "bubble" to the top of the array
