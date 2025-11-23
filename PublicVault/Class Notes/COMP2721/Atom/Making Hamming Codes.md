---
tags:
  - ComputerArchitecture
Class: COMP2721
Reviewed: false
---
 - Bits whos index are numbered are powers of 2 are called [[Basic Error-Correcting Code Theory#Definitions#Parity Bits/Check Bits/Redundant Bits|Parity Bits]]
 - Other bits are called Data Bits
>[!NOTE] Create the Hamming codeword for the following dataword ... using **EVEN** parity
> 001110

1) We know we need to store those 6 bits
   `Codeword: _ _ _ _ _ _`
2) Assign place values to each bit
   `Codeword: _ _ _ _ _ _`
   `          1 2 3 4 5 6`
3) Don't put anything in the powers of 2
	`Codeword: x x _ x _ _`
	`          1 2 3 4 5 6`
4) put all the bits of the dataword you want to store into what remains
   	`Codeword: x x 0 x 0 1`
	`          1 2 3 4 5 6`
5) Extend the codeword to fit the remaining bits, keeping in mind you cant store data in powers of 2
   	`Codeword: x x 0 x  0 1 1 x  1 0`
	`          1 2 3 4  5 6 7 8  9 10`
6) Any index position that is not a power of two, break down into a sum of powers of 2
	`Codeword: x x 0 x  0 1 1 x  1 0`
	`          1 2 2 4  4 4 4 8  8 8`
	`              1    1 2 2    1 2`
	`                       1       
7) The Parity Bits check the Data Bits who contain their index in the breakdown and add up the data they contain
	- If even, store 0
	- if odd, store 1
	`Codeword: x x 0 x  0 1 1 x  1 0`
	`          1 2 2 4  4 4 4 8  8 8`
	`              1    1 2 2    1 2`
	`                       1       
	- In this example, 8 checks index 8 and 10s values
		- 1 + 0 = 1, so odd, so 8 stores 1
	- The goal is to ensure the values of all indexes made up of this index add up to be **even**, hence even parity
	`Codeword: x x 0 x  0 1 1 1  1 0`
	`          1 2 2 4  4 4 4 8  8 8`
	`              1    1 2 2    1 2`
	`                       1       
	- Repeat for the rest of the check bits
	`Codeword: 0 0 0 0  0 1 1 1  1 0`
	`          1 2 2 4  4 4 4 8  8 8`
	`              1    1 2 2    1 2`
	`                       1       
- *To store the data word 001 110 with even parity, we need to actually store the Hamming codeword 0000 0111 10*

>[!NOTE] Create the Hamming codeword for the following dataword ... using **EVEN** parity
> 1000

1) Number the bits required to hold the data word
```
Codeword: _ _ _ _
          1 2 3 4
```
2) Expand to hold the data word without using any powers of 2
```
Codeword: x x _ x  _ _ _
          1 2 3 4  5 6 7
```
3) Add the data word in
```
Codeword: x x 1 x  0 0 0
          1 2 3 4  5 6 7
```
4) Break the non-power-of-2 index into sum-of-powers-of-2
```
Codeword: x x 1 x  0 0 0
          1 2 2 4  4 4 4
		      1    1 2 2
					   1
```
5) Calculate the power-of-2 index values
 ```
Codeword: 1 1 1 0  0 0 0
          1 2 2 4  4 4 4
		      1    1 2 2
					   1
```
- *To store the data word 1000 with even parity, we need to actually store the Hamming codeword 1110 000*

## Converting between even and odd parity
- Flip any parity bits. Its that easy!