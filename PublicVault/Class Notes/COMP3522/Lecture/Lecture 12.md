![[Profiling]]
# Python Profiler Outputs
- Call Count Statistics
	- Bugs(Surprisingly high calls)
	- Inline-expansion points
		- Places where we can reduce the overhead of calling a function by replacing the call with the body of the function call
- Internal Time Statistics
	- The time it takes for a function to run
	- Can be used to identify "Hot" loops so we can optimize them
- Cumulative Time Statistics
	- Identify high-level errors in algorithms
		- Finding inefficient code and design it
## Running W Python
- Terminal

- ncalls
	- If only 1 number, that is the number of times it was called
	- If 2 numbers, its recursivecalls/primitivecalls

## Limitations
- Runs every 0.001 ms

# Design Patterns
>[!NOTE] "Common design solutions to common architectural problems"
- How can I write a system so:
	- Classes can communicate with low coupling
	- Write systems to classes can be combined to form new structures
	- Classes can be created with different strategies and techniques
### Advantages:
- Don't reinvent the wheel
- Are proven solutions
- Communicate ideas and concepts between developers
- Language agnostic
	- Can be applied to most(if not all) OOP programs
### Disadvantages
- Can make systems more complex
	- Patterns are deceptively 'simple'
- System may suffer from 'pattern overload'
- All patterns have some disadvantage, and add constraints
	- May result in a dev adding a constraint they didn't plan for
- Do not lead to direct code re-use
## Categories
### Behavioral
- Focused on communication and iteration
- Get objects talking with minimal coupling
### Structural
- Combine classes and objects to form new structions
- Focus on architecting to allow for flexibility and maintainability
### Creational
- All about Instantiation
## Picking a pattern
1. Understand the problem
	- Dependencies
	- modularity
	- abstract concepts
2. Identify the category
3. Are there any constraints that I need to follow?
4. Is there a simpler custom solution I can make or use?
## Iterator Pattern
>[!question]  "How do I iterate over a collection of objects with modifying the collection itself?"
- Create a separate class and call it an iterator
- Holds a reference and iterates separately
## Singleton
>[!question] How can I have a globally accessible object, and ensure that there is **only ever one**?
1. **Instantiate** the object on its first use
2. **ideally** hides a private initializer
3. **Reveal** a public get_instance method that returns a reference to a static instance of the class
4. **Provides** global access to the single object
```python
class MySingleton:
	__instance = None

	@staticmethod
	def get_instance():
		if MySingleton.__instance is None:
			MySingleton()
		return MySingleton.__instance
```
