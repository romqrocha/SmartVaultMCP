---
aliases:
  - Processes
---
>[!quote] A program in execution

>[!note] A process is just an instance of an executing program, including the current values of the [[Program Counter|PC]], [[Registers]], and [[Variables]]
- Associated with an [[Address Space]]
- In many [[Operating System]], all the information is stored in a table called the [[Process Table]]
- Processes in [[Unix]] have their memory divided up into the Text segment(The program code), the Data segment(the variables), and the Stack segment.
	- Data grows up, and the stack grows down
	![[UNIX_ProcessSegments.png]]
# Creation
- 4 principle events that cause processes to be created:
	1. System initialization
	2. Execution of a process-creation system call by a currently running process
	3. A user request to create a new process
	4. Initialization of a batch job