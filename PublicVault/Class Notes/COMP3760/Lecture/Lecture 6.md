---
Class: COMP3760
Created: "[[2025 02 14]]"
tags:
  - 0a84ff/Algorithms
  - week/6
Reviewed: false
---
# Transform and Conquer
- Solve the problem by transforming to:
	- A more convenient instance of the same problem 
		- An **Instance Simplification
	- A different representation of the same instance
		- A **representation change**
## Instance Simplification(Pre-sorting)
### Checking uniqueness in an array
### Computing the mode
### Searching

## Representation Change
### Heap
- Idea:
	- Given an array
	- Transform into a new data structure
		- Its a binary tree, but **not** a binary **search** tree
	- Make a *heap* out of it
	```mermaid
	graph TB;
	    A((9))-->B((5))
	    A-->C((8));
	    B-->E((2))
	    B-->F((4))
	    C-->H((6))
	```
#### Characteristics
- A heap is an **almost** complete binary tree 
	- filled on all levels except last
	- Every parent is greater than **or equal to** its children
	- every layer is filled left-to-right
- Max value is the root
- Heap with N elements has height $\lfloor\log_2N\rfloor$
#### Implementation
- Use an array
	- We don't need explicit parent/child pointers, assuming we start at index of 1 instead of 0
	- for index $i$
	- Parent($i$) = $\lfloor i/2 \rfloor$
	- LeftChild($i$) = $2i$
	- RightChild($i$) = $2i+1$
	![[AlgoHeapFromArray.png]]
#### Heap Insert
- Insert into next slot
- "Bubble up" until its a proper heap (AKA "Heapify")
- Efficiency is $O(\log_n)$
1. Add to end of array
2. Check if added item is larger than parent
	1. If it is, switch positions with parent and repeat
#### Heap Delete
1. Exchange root with the last leaf
	- bottom-most, right-most
	- also last item in array view
2. Delete the old root
3. Bubble root down until its heap ordered.
	1. Look at both children
	2. Swap place with the largest, if its larger than the item
	3. Repeat until neither child is larger than the item
- Efficiency is $O(\log_n)$
	- Takes constant time to swap
	- Takes constant time to delete
	- Worst case you bubble a number of times as the height of the tree:  $\lfloor\log_2N\rfloor$
	- so  $1 + 1 + \lfloor\log_2N\rfloor$
#### Heap Construction
- Given an array of numbers
1. Transform array into a heap with keys in the proper order([[#Implementation]])
2. Starting with the last(rightmost) parental node, fix the heap rooted at it if it doesn't satisfy the heap conditions([[#Heap Sort]])
	- Repeat until heap condition is met
3. Repeat Step 2 for each preceding parental node
- Complexity is $O(n\log n)$
	- There are ~$N/2$ parental nodes -> $O(n)$
	- $\log N$ steps to fix each node -> $(O(\log n)$)
	- $O(n) + O(\log n) = O(n\log n)$
#### Heap Sort

4. 