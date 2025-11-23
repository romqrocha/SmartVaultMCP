# Profiling
- Analyzes the programs runtime performance:
	- Space complexity
	- Time complexity
	- Usage of particular instructions
	- frequency and duration of function calls
- using [[Profilers]]
- A form of *dynamic program analysis*
- Works by *instrumenting* the source code
- Instrumentation adds code to collect runtime information
- Can also do other things, such as:
	- Events
	- stats
	- simulations
	- Hardware interrupts
	- OS hooks
- Creates a *profile*
## Trace
- A live stream of events while the program is run
- Used for parallel programs
## Profile
- Can slow down a program because it adds extra logic
- Still gives an idea of how well the code is running
> [!cite] "The *resolution* is limited"
