---
aliases:
  - TSL Instruction
  - TSL
---
>[!note] Reading and Writing a word are guaranteed to be indivisible.
>No other processor can access the memory until the instruction is finished.
>**The [[Central Processing Unit|CPU]] executing the TSL instruction locks the [[System Bus|Memory Bus]] until it is done.**

# x86
```asm
enter_region:
	MOVE REGISTER,#1
	XCHG REGISTER,LOCK
	CMP REGISTER,#0
	JNE enter_region
	RET

leave_region:
	MOVE LOCK,#0
	RET
```