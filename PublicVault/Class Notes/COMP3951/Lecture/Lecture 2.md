# Cross Platform Targeting
- DotNet has various models for development that all compile down to the DotNet standard library

# ASP(Active Server Page)


## NTDLL
Interface that operates with the OS

OS runs on a Kernel Level, but contains a microkernel

# Process Execution
## Native Code
- an Application(.exe file) becomes a **process** in execution
- OS allocates and creates memory for:
	- Process Control Block
		- Created in Protected area of memory
		- Contains 
			- metadata about the process
			- The state(Running/blocked/suspended)
			- All the registers when the process is interrupted
		- Windows also creates a Main Thread Control Block
	- Data(AKA Heap)
		- Where variables are allocated
		- Global variables are also allocated here
	- Code
		- All the instructions, in Binary, ready to be executed
	- User Level Stack
		- Holds local(function) variables
		- Also holds pointers to instructions so we can track the instruction stack 
	- System Level Stack
		- Passing parameters during system calls
		- Protects the system from user crashes
	- Kernel Level Stack
		- Stores local variables and system variables that are used during a hardware/System level function execution
## Managed Code(C#/Java)
- exe file is not in binary, but in an Intermediate Language
- Memory allocation is managed by the Garbage Collector(GC), not the OS
- You can mark a portion of code as `unsafe` and manage the memory manually
- Local variables are allocated on the stack
- No global variables

# Stacks
## Passing parameters/storing locals
- FILO
- Used for temporary variables
- Passed either by reference or value
- By Value:
	- A copy is created and pushed to the stack
	- original is not affected
- By Reference:
	- The **address** of that value is passed
	- Two type: in/out and out
	- In/Out:
		- Gets the values from the address
		- Uses it
		- Updates it before returning
	- Out:
		- Only writes the value at the destination memory address
- 