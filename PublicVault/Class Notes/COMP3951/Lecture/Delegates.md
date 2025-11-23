# Delegates
- A pointer to a function
- Implemented in `System.Delegate`
- Constructs in C# are constructs to allow scenarios are the implemented with function pointers
- Think of it as a functional interface
- Delegate doesn't know what's implemented, just that the input/output meets the requirement
- 
# Threads
- 
# 


# Mutex

# Semaphore

# DLL
- 3 steps for the creation and loading of an exe
	- Compiling
	- Linking
		- Linking is now done during by the compiler
	- Loading
- DLL is a windows term
	- Linux/Unix use a "Shared object" (.so file)
	- Mac OS has .dylib(dynamic library)
- Two types of libraries
	- Static
		- Compiled directly into your code
	- Dynamic
		- Independent from the application
		- Linked at load time
			- Application makes explicit calls to DLL functions, like local functions
		- or at runtime
			- A program calls either `LoadLibrary()` or `LoadLibraryEx()`to load the DLL
- Advantages
	- Modularization of code and architecture
	- Code reuse
	- More efficient memory usage
	- Eases deployment and installation
- Disadvantages
	- Can be missing
	- Obsolete or different versions
	- 