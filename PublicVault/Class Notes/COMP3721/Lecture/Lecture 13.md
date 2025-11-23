---
Class: COMP3721
Created: "[[2025 02 18]]"
tags:
  - 0a84ff/DataComm
  - week/7
Reviewed: false
---
# Error Checking
## Block Coding
- See [[Making Hamming Codes]] and [[Detecting and Correcting Errors with Hamming Codes]]
- To guarantee detection of up to $s$ errors in a block coding scheme, the minimum [[Hamming Distance]] between all pairs of valid codewords must be $d_{min} = s+1$
## Cyclic Codes
- Hamming codes with 1 extra property: If rotated, the result is another codeword
- Advantages:
	- Good performance in detecting single-bit, double error, and burst errors
	- Easily implemented, because bit shifting is fast
	- Can be implemented in software AND hardware
- [[Cyclical Redundancy Checks]] typeOf

## Checksum
- Can be applied to a message of any length
	- used [[Network Layer]]
	- used [[Transport Layer]] 
	- not-used [[Data-link Layer]]
- In addition to sending the data, we send the sum of the data and append the sum to the message
- If the sum is different for the receiver, the message is not accepted
- The sum needs to stills to be the same length as the chunks of data in the message
	- We use 1's compliment arithmetic to compress our sum
	- If the sum is larger than the chunk size, $m$, we wrap the extra leftmost bits to the right of the sum
	- `100100` changed to 4 bits would be $(10)_2 + (0100)_2 = (0110)_2$ 
	- Then we flip the bits, so $(0110)_2 = (1001)_2$
		- Ones compliment has 2 zeros, so for positive zero we set all bits o 0, and for negative we sent all bits to 1
	- The reason we flip is to ensure the message sum plus the negated sum will equal 0
## Forward Error Correction(FEC)
- Retransmission of corrupted and lost packets isn't useful for real-time multimedia transmission due to unacceptable delay in reproducing
- Because of this, we need error correction AND detection
### Hamming Distance
- to **correct** errors, we need more distance
	- for $t$ errors, we need $d_{min}=2t+1$ bits
	- e.g. for a 10 bit packet, we need a 21 bit distance
### Using XOR
- Break the data into chunks
- Create a redundancy chunk by creating an XOR($\oplus$) of all the chunks
- If any chunk if lost or corrupted, we can insert the redundancy chunk into the corrupted chunks place and redo the XOR to recreate the chunk
### Chunk Interleaving
#TODO: Review the slides for this