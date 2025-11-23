---
Class: COMP2721
tags:
  - ComputerArchitecture
Reviewed: false
---

Figure 1-2 is the bulk of the first quiz!
# Overview
- Modern computers are the results of many compromises
	1) cheaper
	2) backwards compatibility
	3) simpler
# John von Neumann
- Built the math frameworks for Quantum Physics, Game Theory
- Wrote a paper about his experiences advising on on ENIAC and EDVAC
		- ENIAC was decimal
		- EDVAC was one of the earliest binary electronic computers and used binary
	- This paper described a computer that stored its data and program in the same address space, unlike earlier computers that stored data in memory(paper, for example) and programs(dipswitches/physical plugs) separately.
	- Became the basis on modern computers
	- Invented the merge-sort algorithm
[[Terminology]]

# 6 Level von Neumann machines

5) P-O/Language - Java or C, for example
   Compiler
4) ASM
   Assembler
3) O/S
   Interpreter
2) ISA
   Interpreter
1) MA
   Hardware
0) DLL

- The ONLY thing bad about this is that its **very slow**
## Advantages
- As we go up levels
	- it gets easier and easier for people
	- Programs get smaller
	- Instructions get more powerful
	- Modular
		- If you swap an Operating system, you only need to change the assembler and the ISA interpreter
		- if you swap from Java to C, you only need a new compiler
# Interpretation vs Compilation
- Interpretation converts each High-Level Language instruction into the equivalent set of Lower-Level Language instructions, one instruction at a time.
	- JavaScript, PHP
- Compilation converts each High-Level Language instruction to the equivalent to the equivalent set of Lower-Level Language instructions, all at once, then the original HLL program can be discarded.
	- C

![[Powers of programming language]]
