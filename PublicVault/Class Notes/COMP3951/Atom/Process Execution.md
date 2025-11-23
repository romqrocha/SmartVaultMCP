1. EXE is run
2. OS allocates blocks of memory for:
	- Process Control Block
		- Metadata about the process
		- State of the process
		- Contents of the register, when interrupted
	- Heap
		- Global variables(There are none in C#)
		- Objects
	- Code
		- Binary instructions
	- User Stack
		- Function parameters
		- local function variables
		- return address
	- System Stack
		- Parameters for System Calls
		- Only used when interacting with the OS
3.  On a function call, the system push