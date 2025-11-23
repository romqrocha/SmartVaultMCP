---
aliases:
  - OS
---
 >[!quote] Operating Systems turn ugly hardware into beautiful abstractions
- Is the most fundamental piece of software
- Runs in [[Kernel Mode]]
- Runs other software in [[User Mode]]
	- #question can the OS can run other software in Kernel Mode - e.g. "run as administrator" in windows.
- Examples:
	- [[Linux]]
	- [[Windows]]
	- Mac
- Can be:
	- Software
	- An extended machine
	- [[#OS As a Resource Manager|A resource manager]]
- Why use? Instead of manually writing code to read from a hard drive, we can use an OS-abstraction: `ssize_t read(int fd, void *buf, size_t count);`
- Basic structure consists of:
	1. Main program to invoke service procedures
	2. A set of service procedures to handle system calls
	3. Utility procedures to support service procedures
- Must be fully aware of all [[Registers]]s
# OS As a Resource Manager
- Provides many [[Software Abstraction|Abstraction]] layers
- Ways to view:
	- Top-Down
		- Provides abstractions to applications
	- Bottom-Up
		- Manages pieces of a complex system
		- Provides orderly, controlled allocation of resources
- Resource Management includes [[Multiplexing]]

