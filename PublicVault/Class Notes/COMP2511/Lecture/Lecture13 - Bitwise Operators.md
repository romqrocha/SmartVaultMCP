---
Created: 2024-07-08T19:58
Class: COMP2511
Reviewed: false
---
# Bitwise Operators

- Have to be used with integral types
- Typically used with unsigned ints or longs
- Bitwise data manipulations are **machine dependent**

|Name|Command|
|---|---|
|bitwise AND|&|
|bitwise OR|\||
|bitwise XOR|^|
|left shift|<<|
|right shift|>>|
|complement|~|

- left shift shifts all the bits in the **left** operand to the left by the number of bits specified in the **right** operand
- right shift is left, but shifts to the right rather than the left
- complement flips all 0’s and 1’s in its **operand**
- Each operator, sans complement, has an assignment version

|   |   |
|---|---|
|Name|Command|
|bitwise AND|&=|
|bitwise OR|\|=|
|bitwise XOR|^=|
|left shift|<<=|
|right shift|>>=|