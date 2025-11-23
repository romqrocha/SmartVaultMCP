- Processing multiple things in parallel
	- True: Using multiple processes
	- False: Using threads and tasks
	- Usually notifies the main thread of completion or failure through a callback
- Different types:
	- [[Pre-emptive Multitasking]]
	- [[Cooperative Multitasking]]
# Python
## Threading
- Creating different threads that execute parts of our code in parallel.  
- Runs on the same core.  
- Good for [[IO Bound problems]]
## Tasks
- Units of work defined using AsyncIO and Coroutines (More on this later).  
- Good for I/O Bound problems
## Multiprocessing
- Creates a whole new process with its own address space and Python interpreter.  
- Runs on different CPU cores.  
- Good for [[CPU Bound problems]]