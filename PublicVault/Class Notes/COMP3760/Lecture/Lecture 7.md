---
Class: COMP3760
Created: "[[2025 02 21]]"
tags:
  - 0a84ff/Algorithms
Reviewed: false
---
# Space/Time tradeoffs
- Space is memory
- time is time
- always a tradeoff
- If space is a concern, we choose an algo that uses less space, but more time
	- Usually in-place modification
	- bubble/selection sort
### Types of tradeoffs
1. Input enhancement
	- Preprocess input to store information to be used later
		- comparison counting sort
		- distribution counting sort
2. Pre-structuring
	- Use the extra space to facilitate faster access
	- arranging data in a way we can use
		- Hashing
		- Hash function
		- Collision handling
# Comparison Counting Sort
- Idea: For each element of a list to be sorted, Count the number of elements smaller than this element and record the results in a table
- $O(n^2)$ time
# Distribution Counting Sort
- Sort an array with a "small"(relative to $n$) set of known values
- Idea: 
	- Count how many of each number
	- Loop over a new array and sort the numbers
- $O(n)$
# String Matching
- String matching character-by-character is slow
- Horspool's algorithm compares characters right-to-left by shifting more than 1 character before comparing again
- Compare the last character of the pattern with the same character at the index of the text
![[Horspool_CompareFinal.png]]
- We know there's no 'I' in 'BARBER' so we can shift the entire word past the 'I'
## 4 Cases
1) Text char $c$ never appears in the Pattern
	- We shift by the entire length of the Pattern
2) Text char $c$ appears in the Pattern, but *not last*
	- Shift by the difference between string length and last index of $c$
	```
		BARBER
	...      B
	# R=6, Last B is 4, so shift is 6-4=2
		  BARBER
		     B
	```
3) Text char *c* appears last in the Pattern, but *only that one time*
	- Shift by entire length
4) Text char $c$ appears last in the Pattern, *and other times*
	- Shift to 2nd-to-last instance of $c$
- There can only be 1 of each number, except max, up to max in the shift table.
	- Its basically how far from the last character in the pattern to this character 
# Hash Maps
- Goal: A way to do fast storage/look-up/retrieval of information based on an arbitrary key
- Efficiency:
	- Insert: usually $O(1)$
	- Get: usually $O(1)$
	- delete: usually $O(1)$
	- There are always degenerate cases, in which case we can end up with $O(n)$ time
	- Implementation is important, and must distribute the keys evenly
- Sorted arrays:
	- Insertion/deletion: $O(n)$
	- Lookup: $O(\log _n)$
- Unsorted array:
	- Insertion is faster: $O(1)$
	- Lookup is slower: $O(n)
	- Deletion is the same
## Hashing
- Each item has a unique key
- Uses a large array called a Hash Table
- Uses a **Hash Function** to map keys to an index in the table
- Common hash function: For table size $m$, `key mod m`
- If key is not a number, map it to a number
	- with strings, we can add the ordinal values of the chars, the  mod that
## Collisions
- Occur when different keys are mapped to the same bucket
### Separate Chaining
- Each bucket is not a single item, it becomes a (linked) list of all the people who map to that bucket
- Doing this means insertions stay fast, but lookup becomes slower
### Closed Hashing with Linear Probing
- Computer the hash
	- If bucket is empty, store the value in it
	- If there's a collision, linearly scan for the next free bucket
		- Treat the table as a circular array
		- so if we hit the end, we go back to the beginning of the table and check from there
- For this technique, the table must be at least size $n$
## Hash Functions
- The efficiency of hashing depends on the quality of the hash function
- A "good" has function will:
	1. distribute the keys uniformly over the buckets
	2. produce very different hash-codes for similar data
- Hashing of numbers is easy, we just distribute them over the buckets with `key%numBuckets`
- Strings are a little more complicated:
	- A better hash algorithm for strings is
	```
	alpha = |alphabet| //size of alphabet used
	hash = 0
	for i = 0 to s-1 do
		h = h + (ord(c_i) * alpha^(i))
	code = h % numBuckets
	```