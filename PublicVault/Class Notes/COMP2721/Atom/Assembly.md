---
Class: COMP2721
Created: '[[2024 11 21]]'
tags: 
Reviewed: false
---
# CISC
- Complex Instruction Set Computers
- Functions, data structures, and loops
- "low performance"
- Multiple cycles
- Architectures
	- Intel x86 Architecture
	- uses NASM standard
	```
	
	```
# RISC
- Reduced Instruction Set Computer
- Simple programs, no data structures no functions
- "high performance"
	- more registers
	- s registers are literally s-latches
- single/simple cycle / cycle
- Architectures
	- arm v7

## Registers
- r0 -> r3
	- intermediate values(variables)
- r4 -> r11
	- Register variables
- r12
	- routine/subroutine (functions)
- r13(sp)
	- Stack Pointer
	- push/pop values 
- r14(lr)
	- Link Register
	- referring to return values of functions
- r15(pc)
	- Program Counter
	- DO NOT TOUCH IT
- r16 and 17 are for program status / flags
	- r16(cpsr) 
		- current program status register
	- r17(spsr)
		- saved program status register
	- flags:
		- N
			- Negative
			- Raises when we return a negative value
		- Z
			- Zero
		- C
			- Carry-out(arithmetic)
		- V
			- oVerflow
		- I
			- Interrupt