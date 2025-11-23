---
Class: COMP2721
Created: '[[2024 09 26]]'
tags: 
Reviewed: false
---
ASK JASON ABOUT SYNDROME BITS CALCULATION
I HAVE NO IDEA WHAT HE WAS DOING

- starting with a parity bit, count and skip that many bits
	- e.g. bit 1 counts 1, skips 2, counts 3, skips 3
	- bit 8 counts 8, 9, 10, 11, 12, 13, 14, 15, skips the next 8
- xor the values in each bit position instead of addition, that gets you 0 or 1
- 

# Question 1
```math
#r = variable we want to calculate 
#t = number of bits you can correct
#k = number of bits of dataword
#i = index
#n = k + i

#2^y >= Σ(n choose i)
```

# Question 2
```math 

#1 0 1 1  0 0 1 0  1 1 0
#    1    1   1    1   1
#    2      2 2      2 2
#         4 4 4         
#                  8 8 8

ones = 1 xor 1 xor 0 xor 1 xor 1 xor 0
twos = 0 xor 1 xor 0 xor 1 xor 1 xor 0
fours = 1 xor 0 xor 0 xor 1
eights = 0 xor 1 xor 1 xor 0 

```
