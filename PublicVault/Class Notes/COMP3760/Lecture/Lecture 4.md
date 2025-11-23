---
Class: COMP3760
Created: "[[2025 01 31]]"
tags:
  - 0a84ff/Algorithms
  - week/4
Reviewed: false
---
# Decrease and Conquer
- Come up with a recursive solution that solves a smaller version of the current problem, then solve that problem.
- Phase 1:
	- Reduce the problem to a smaller version of the same problem
	- Solve that smaller problem
- Phase 2:
	- Extend the solution of the smaller instance to get the solution of the original problem
	- Extend, augment, enhance, adapt, adjust
	- Sometimes this part can be a single line of addition or subtraction
- Can be implemented:
	- Top-down(recursively)
	- Bottom-up(iteratively, for/while loop)
- Three types:
	1. Decrease by a constant(usually 1)
		- Insertion sort
		- Generating permutations
		- Generating subsets
	2. Decrease by a constant *factor*(usually half)
		- Binary search
		- Exponentiation by squaring
		- Fake coin problem
	3. Variable-sized decrease
		- Euclid's algorithm
## Generating Permutations
To find all permutations of `n` objects:
1. Find all permutations of $n-1$ of those objects
2. Insert the remaining object into all possible positions of each permutation of $n-1$ objects
## Generating Subsets
- There are $2^n$ subsets of a set of $n$ elements
- To find all subsets of a set with $n$ items
1. Find all subsets of a set with $n-1$ of the items
2. Copy/clone the subsets
3. Insert the last item into each subset of the copy
4. Merge the two subsets together
## Insertion and Selection sort
1. Make 2 piles: Sorted and Unsorted
2. Each Main iteration places an item from Unsorted into the appropriate position in Sorted
- Number of iterations is $O(n)$ or $O(n^2)$ in worst case
- Selection Sort Main Iteration:
	1. Choose from unsorted ($O(n)$)
		- Linear search
	2. Place into sorted ($O(1)$)
		- Goes at the end
- Insertion Sort Main Iteration:
	1. Chose from Unsorted($O(1)$)
		- Choses the first item
	2. Place into Sorted Part ($O(n)$)
		- Shift the other items to make space for the newly inserted item
## Decrease by a constant Factor
- Think Binary Search
	- Requires a sorted array
	- We cut the index we search in *half* each time
- Generally $O(log_fn)$ where f is the factor

## Exponentiation by Squaring
- Compute $a^n$ where $n$ is a non-negative integer
	- For even values of $n$, $a^{n}=(a^{n/2})^{2}$
	- For odd values of $n$, $a^{n} = (a^{(n-1)/2})^{2}a$
- Example: $a^{38}$
	- $a^{38} = a^{19} * a^{19}$
	- $a^{19} = a * a^9 * a^9$
	- $a^9 = a * a^4 * a^4$
	- $a^4 = a^2 * a^2$
	- $a^2 = a * a$
	- This has 1-2 operations per step, but divides the result in half each step
	- therefore, the worst-case of this is $2log_2n$
## Fake Coin problem
- A mischievous banker gives you n identical-looking coins, but tells you one is a fake (it is made from a lighter metal). Luckily, you have a balance scale, and can compare any two sets  of coins. 
- Design an efficient Decrease by a Constant Factor algorithm that finds the fake coin.
1. Split the pile in half
2. The lighter side has the fake, so split that half and restart
3. If odd number of coins, and both piles are even, the leftover coin is the fake.