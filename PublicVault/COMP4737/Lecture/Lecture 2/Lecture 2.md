# Monolithic System
- All [[Operating System|OS]] Components operate within a single address space and share the same privilege level
- Offers high efficiency but high complexity
- Stability is a concern; errors in one component can crash the entire system
- System lacks modularity
- Used by [[Linux]], [[Windows]]
# Layered System
- [[Operating System|OS]] is organized as a hierarchy of layers
- each layer relies on the layer below it
- Simplifies design and debugging; enhances modularity
- Can introduce overhead and is less efficient than 
# Microkernel
- Split the [[Operating System|OS]] into small, well defined modules
- Goal is to achieve high reliability
- Only one module, the Microkernel, runs in kernel mode
- Easy to add new modules, stable.
- Performance overhead, complex design
# Client-Server
- [[Server]] provide services
- [[Client]] uses these services
- Communicate between them is often by passing messages
- The model is an abstraction that can be used for a single machine, or a network of machines
# Virtual Machine
- Allows you to run two or more [[Operating System]] on one machine
- Two types:
## Type 1 Hypervisor
- Runs directly on the system hardware
- No need for an operating system
- Example: `ESXi` (Elastic Sky X Integrated)
## Type 2 Hypervisor
- Example: `Virtualbox`
- Simulates a machine on top of the Host Operating System
# Clock Hardware
>[!note] All the clock hardware does is generate interrupts at a known interval.
- Advantage of a programmable clock is that the interrupt frequency can be controlled by software
- Contains 3 components:
	1. Crystal oscillator: Generates a [[Periodic Signals]]
	2. Counter: Signal is fed into the Counter to make it decrease. When it hits zero, it causes a CPU interrupt
	3. Holding register: Value of the holding register is copied into the register
### Modes
- One-Shot mode:
	- When the clock is started, it copies the value of the holding register into the counter, and decrements the counter at each pulse.
	- When counter gets to zero, it causes an interrupt and stops until explicitly started again by software
- Square-wave mode:
	- After getting to zero, raises an interrupt
	- Holding register is copied into the counter
	- Process is repeated indefinitely; called a Clock Tick
# Clock Software
- Typical duties of a clock driver:
	1. Maintaining time
	2. Preventing processes from running longer than allowed
	3. Accounting for CPU use
	4. Handling alarm system calls from user processes
		- Process can request that the OS raises a warning
	5. Providing watchdog timers for parts of the system
		- Detect and recover from crashes or infinite loops
		- May reset a system that stops running
		- Used lots in embedded systems
	6. Profiling, monitoring, stats gathering
