---
tags:
  - ComputerArchitecture
Class: COMP2721
Reviewed: false
---
# Definitions

## Error-correcting Code
Used for detecting and (possibly) correcting errors
## Data Word/Memory Word
 Raw data word we want to protect and store(usually in RAM) without error
## Codeword
The data word with extra bits added. The bits are called Parity Bits 
## Parity Bits/Check Bits/Redundant Bits
Allow us to detect/correct errors
## Code
A code is a set of words we agree are valid, like a dictionary
## Hamming Distance( HD )
- The minimum number of bits different between any 2 valid words in a code
- The Hamming Distance of a code is the distance between its two closest words
- How different two words are from each other.
- A larger Distance means they are MORE different
- This means an 8-bit code has a maximum hamming distance of 3 bits because at 4 bits its AS CLOSE to 0000 0000 and 1111 1111, and more than 4 bits means it looks MORE like 1111 1111 than 0000 0000
- This means
	- code with Hamming Distance of *h* bits can detect up to **LESS THAN h** number of bit differences between any 2 words in a code
	- code with Hamming Distance of h bits can correct up to **less than h/2** bits of error
- We want large gaps between valid codewords
- We want a large hamming distance
# Basic Error-Correcting Code Theory
- Sometimes we can detect and correct errors
	- Sometimes we can detect, but not correct
	- Sometimes neither

- Hamming Code is an official protocol for error detecting and correction
- If we wanted to create a code with two words, we could pick 0 and 1
	- This would be terrible because if some error happened and a 0 got changed to a 1, we couldn't detect it
	- Can solve this by making longer words
- So we agree to make longer words, using 0000 0000 and 1111 1111
	- Now if something goes wrong, it is likely to only affect 1 digit
	- if I get 0001 0000, I can assume you meant 0000 0000
- The worst potential errors:
	- 0000 1111
		- We have no way to attempt to determine which value you meant to sent
	- 1111 1000
		- If you sent all 0, then this error would lead to a bad fix
	- 1111 1111
		- If you sent all 0, this looks like a proper value, so we wont even assume there's an error
		- Uncorrectable, undetectable
- Detection is quite easy, correction is more difficult
- There is a tradeoff of *clarity* and *efficiency*
	- To get clearer words, we need longer words with lots of differences between them
	- To check if a long word has errors, and to fix the errors, is slow
- A odd number of bits makes a 50/50 word impossible to exist, so it means we can never have that type of error
	- e.g. Code A retrieves 0 0000 0111
		- This is either 3 bits wrong, and was suppose to be 0 0000 0000
		- or 5 bits wrong and was suppose to be 1 1111 1111
		- We could not fix 4-bit errors with our 8 bit code, but we can now!

# CSMA/CD
- CD means Collision Detection
- Station monitors the medium after it sends to see if a collision occurred or not. It resends the frame when a collision occurs
- used-by [[LAN]]
![[DataComm_CSMA-CD.png]]