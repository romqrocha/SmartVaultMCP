- A kind of lightweight [[Process]]
- A sequence of instructions that can be executed independently
- A process can run multiple threads
- Threads operate within the same address space, so they share the same resources and data
# Python
## Setup
- 3 ways
	1. Create an object of type Thread and assign a function to it
	2. Inherit from thread and create your own
	3. Create a Thread Pool Executor
## Thread Pool Executor
- Creates a bunch of threads that automatically handle completing a set of tasks
- Allows us to reuse threads instead of constantly creating/destroying them