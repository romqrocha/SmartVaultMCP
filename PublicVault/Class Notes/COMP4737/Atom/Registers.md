---
aliases:
---
- Small piece of [[Memory]] directly connected to the CPU.
- Local, super fast.
- Size on the order of 32x32 bits on a 32-bit CPU or 64x64 bits on a 64-bit CPU
```math
32 bits * 32
64 bits * 64
```
- All CPUs contain come registers to hold key variables and temporary results;
	- [[Program Counter]]
	- [[Stack Pointer]]
	- [[Program Status Word]]
- All data used in CPU operations **must** be in a register first.
- 8 bit registers are `A`, `B`, `C`, etc.
- 16 bit registers are `AX, BX`, `CX`
- 32 bit registers are `EAX, EBX`, `ECX`
- 64 bit registers are `RAX, RBX`, `RCX`
- `A`-type registers contain system call number
- Other registers contain arguments
- `A`-type register often contains the return value as well
```
push rbp //Push register base Pointer
mov rbp, rsp //Move the register base to the stack pointer
```