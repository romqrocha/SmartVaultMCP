# Collections
- We need them to manage groups of related objects
- Two types: Generic and Non-generic
	- `System.Collections` - Considered obsolete
	- `System.Collections.Generic`
- Two ways to group: Array or collection
- Arrays are strongly type, static length
- Collections provide flexibility
- A collection is a class you need to instantiate
## Non-generic collections:
- Require typecasting when retrieving elements
- Considered obsolete for most applications due to performance issues
## Generics
- Use type parameters(`<T>`)
- Provide strongly-typed data structures
### Advantages
- Type safe
- Performant:
	- No boxing/unboxing
- Reusable
	- Allows the same code to work with different data types
- Memory usage
	- Non-generic collections must store elements as objects, so they have to box primitives, which consumes additional memory
## Choosing a collection:
- Ordering (`List<T>`)
- Uniqueness (`HashSet<T>)
- Thread safety (`ConcurrentDictionary<T>`)
# Concurrency
> [!error] Issues arise when multiple threads or processes access shared resources at the same time
- Process control block
	- Contains metadata about the process
		- Who is the owner
		- Priority
	- Just a container
- Thread control block
	- The execution body
	- In multi-threaded programs, we might have multiple
	- The state of the execution
	- Is the thread running
	- content of registers at timeout
- OS controls thread execution
	- Like a heartbeat
	- When thread timeouts
		- OS updates the Thread Control Block with current register and PC
		- OS loads the next threads registers and PC from its control block and allows its to execute until timeout
- Execution of the processes/threads is performed in parallel:
	- True Parallelism happens on different processors
	- Pseudo-Parallelism happens on the same processor
## Critical Section
- Sections of code in a process/thread that access a set of shared variables or resources
## Race Condition
- When the order of process/thread completion can make a difference in the output
- Considered bad because processes should be deterministic
## Mutual Exclusion
- Mechanisms for avoiding race conditions by preventing two processes/threads from running in their critical sections
- **Must be enforced**
	- Can be done with hardware or software
- **Threads** need Synchronization
- **Processes** need communication AND synchronization
### Requirements
- A process that stops executing must do so without interfering with other processes
- No deadlocks or starvation
- Must not be denied access to a critical section when there are no other processes using it
- No assumptions should be made about the relative process speeds or number of processes
- A process remains inside its critical section for a finite time only.
## Thread Safe
- Means data or resources that are address concurrently are safe and correctly updated
- Can be access and modified without causing race conditions
- There are also synchronization mechanisms such as Semaphores and Monitors
- C# lock and monitor can cause performance issues or deadlocks
# Process
>[!note] An executable program in execution
- In Unix/Linux, OS processes the execution
- In Windows a process is a container and **threads** execute
	- A process has:
		- A process control table:
			- Unique ID([[PID]])
			- Information about the owner, day, parent, process, etc.
			- List of opened handles to resources
			- Security Context(Access token) that identifies the user, security group, privileges
		- Private virtual address space
		- At least one thread for execution
	- When created Windows will create:
		- The process control table
		- Main thread
		- Data and code segments to be shared by threads
# Threads
> [!note] A unit of execution inside of a process
- In Unix/Linux, is more of a clone of a process
- In Windows, Threads execute and are scheduled for execution rather than the process itself executing
- A thread has:
	- A Thread Control Table:
		- Unique thread ID(Client ID)
		- Control information
			- State of execution
			- priority
			- scheduling information
		- Processor state
			- The context of execution -> The contents of the CPU registers containing the state of the processor at time out.
		- In some cases, security context
	- Two stacks:
		- User Level Stack
		- Kernel Level Stack
	- Thread Local Storage(TLS) used by Run-time and Dynamically-Linked libraries
	- Share the address space of the process
		- The data and code segments