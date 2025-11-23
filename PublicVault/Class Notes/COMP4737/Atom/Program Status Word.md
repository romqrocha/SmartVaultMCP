---
aliases:
  - PSW
---
- Contains the condition code bits, which are set by:
	- Comparison Instructions(EQ, NEQ, GTE, etc.)
	- CPU Priority
	- The Mode([[User Mode]] or [[Kernel Mode]])
	- and various other control bits
- [[User Mode]] programs may read the entire PSW, but may only write to some of the fields
- Plays an important role in System calls and I/O
# Control Bits
![[EFLAGS_ControlBits.png]]
- CF(Carry Flag) - Set if an arithmetic operation generated a carry or borrow from the most-significant bit; cleared otherwise
- PF(Parity Flag) - Set if the least-significant **byte** of a result contains an even number of 1 bits; cleared otherwise
- AF(Auxiliary Carry Flag) - Like CF, but only for bit 3 of the result. Used in Binary-Coded Decimal (BCD) Arithmetic
- ZF(Zero Flag) - If the result is 0.
- SF(Sign Flag) - 0 for positive, 1 for negative
- OF(Overflow Flag) - Indicated the result is too large or too small to fit in the destination operand. Indicates an overflow for [[Two's Complement]] arithmetic
- I/OPL(I/O Privilege Level) - How much privilege the current program or task has. The Current Privilege Level(CPL) must be less-or-equal to the level required to access the address space. POPF and IRET can modify only then operating at CPL of 0.