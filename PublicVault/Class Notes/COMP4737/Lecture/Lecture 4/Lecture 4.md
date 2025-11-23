# System Initialization
- When a [[Operating System|OS]] is booted, a bunch of processes are automatically made
	- Foreground Processes; interacting with Human users and performing work for them
	- Background Processes; Not associated with any user, but have some specific function.
# Process Creation
- Processes can be made by:
	- A currently running process(fork, in linux)
	- A user request(clicking an executable file)
	- Initializing a batch job(Thread pools)
# Process Termination
- Condition that cause a process to Terminate:
	1. Normal Exit(voluntary)
		- When the process has finished its job; either by the user clicking the close button or the system reaching the end of main
	2. Error Exit(voluntary)
		- When you enter an incorrect argument list in a command line program, and it doesn't run
		- When you give bad input to a GUI form and it tells you to try again
	3. Fatal Error(involuntary)
	4. Killed by another process(involuntary)
		- Unix: `kill`
		- Win32: `TerminateProcess`
# Process Hierarchies
## Unix
- Process and all its children, and all their children, form a *process group*
- Signals from keyboard are delivered to all members of the process group
- Each process can individually catch, ignore, or take the default action for the signal(which is to be killed)
## Windows
- No process hierarchy. All processes are equal.
- When a process creates a process, the parent is given a token(a handle) that can be used to control the child.
	- The parent can pass this token to other processes, effectively "passing ownership" of a process to another process
# Process States
1) Running
2) Ready(Scheduled)
3) Blocked(usually by external event)
![[Process_States.png]]
# Process Implementation
- The [[Operating System|OS]] maintains a table called the [[Process Table]]
- Its important to implement [[Multiprogramming]] to ensure the CPU is constantly being used.
# Thread
>[!note] A thread is a flow of execution through [[Process]] code. Each thread has its own program counter, system registers, and stack.

- Also called a *Lightweight process*
- Improve application performance through [[Parallelism]]
- All threads share the same memory space, which means they share the same global variables
## Motivation for threads
- Allows for blocking sections of a program to wait while other work is done
- Lighter weight than processes, easier and faster to create and destroy.
- No performance gain when all threads are CPU bound; best used when there are lots of I/O processing required
- Useful on [[Multicore Processors]]
## Implementation in User Space
- threads package is put entirely in user space
- Kernel thinks it is managing single-threaded processes
- Can be implemented on Operating Systems that do not support threads
- Threading is implemented by a library
- Each process needs its own [[Thread Table]] to keep track of the threads is using.
	- Thread table is managed by the run-time system
- Pros:
	- No context switch is needed
	- Memory Cache doesn't need to be flushed
	- Super fast because of above reasons
	- Allow each process to have its own custom scheduling algorithm
	- Scale better
- Cons:
	- If any individual thread raises a blocking system call, the whole process is blocked because the OS thinks there's only 1 thread.
	- If a thread starts running, no other thread in the process can be run unless the thread gives up the CPU
## Implementation in Kernel
- The Kernel has a [[Thread Table]] that keeps track of all threads in the system
	- Information is the same as user-level threads, but is kept in the Kernel
- Because the Kernel knows the status of all the different processes **and** threads, the Kernel can run different threads from the same process **or** a thread from a different process when a block occurs.
- Do not require new non-blocking system calls
- Cons:
	- Substantial cost to system calls, so creation/termination has more overhead
## Hybrid Implementation
- One-or-more Kernel threads are assigned to one-or-more user threads
- Gives the programmer lots of flexibility
## Pop-up Thread
- Created to handle arrival of system messages
- Latency between message arrival and start of processing is very short
- Since each thread if brand new, there is no history(register, stack, etc.) to be restored.