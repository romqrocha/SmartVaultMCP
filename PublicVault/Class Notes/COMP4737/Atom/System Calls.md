---
aliases:
  - System Call
---
>[!note] An interface between the [[Operating System]] and [[User Mode]] Programs

- Vary from OS to OS
- Highly machine dependent; often expressed in assembly
- Are performed in a series of steps
	1) Push parameters onto the stack in reverse order
	2) Call the library procedure; the normal procedure call to call *all* procedure calls
	3) The library procedure puts the call number where the OS expects it; usually a register
	4) Executes a [[Software Interrupts|Traps]] instruction to switch from User Mode to [[Kernel Mode]], and start execution at a fixed address in the Kernel
	5) Kernel code examines the system call number, and dispatches to the correct handler
	6) Handler runs
	7) Control returned to user-space code
- Can either be [[Blocking]] or [[Non-Blocking]]