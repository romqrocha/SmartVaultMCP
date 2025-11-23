---
Class: COMP3951
---
- 3 categories
	1. Unit Testing
		- Test individual, small functions, methods or modules
		- Should be simple
		- There are usually lots of these
		- They are run automatically
		- Low ROI per test
	2. Integration testing
		- Test different modules working together
		- Done earlier rather than later
	3. functional testing
		- Testing applications overall functionality based on specification
		- The most important aspect is to create cases
		- Generally complicated
		- Take a lot of time to write and run
		- high ROI
# Test Cases
- Tests are based on test cases
- Cases are described with the following:
	- Test Description
	- Prerequisites (If any)
	- Test case input steps
	- Test data(If any)
	- Expected output
	- Tester
	- Date
	- Notes(If any)
# TDD
- Agile methodology
- Involves writing a test after you write *just enough* production code to fulfill the test
- Involves thinking through requirements or design before writing functional code
## Strategies
- Focused on specifications
- Code development is based on short iterations
	- each iteration is based on pre-written unit tests
- Test cases are created as part of the desgin process
## Why?
- Results in better and measurable QA
- Deciphers I/O for functions before writing
- Helps the design process
- Code is more robust
- Brings awareness of side effects of code/code changes
- programmers can make code changes faster and safer
- Migration can be made easer(You can bring the tests over with code to new projects)
## Characteristics
### Unit tests
- A unit test should:
	- be automated
	- be repeatable
	- remain for future use
	- be easy to run
	- be quick to run
- Examples:
	- Functionality based on algorithms with no dependencies
	- A function that displays an error message
	- A validation function
	- sort/search function
## Methodology
- Identify use cases for your application
- Define which features should be implemented
- Write tests for defined use cases
- Test the test first
	- Just return dummy variables from the functions,
	- make sure tests run, compile, pass, fail
- Refactor code
- Repeat
### Visual Studio Test Explorer
- Built in unit testing module for VS
### Unit test method
- Create a unit test project
- write a collection of test
- add a reference to the assembly to be tested
- use the IEEE pattern:
	- Arrange
		- Add a reference to class
		- initialize variables
		- all the setup
	- Act
		- Call the action
	- Assert
		- Check if result is correct
- Test the test
	- Write the test to fail
- Organize based on categories
- Assign priorities
- Test catching exceptions
## Create a unit test project
- Add a new project
	- From templates, select Unit Test Project
	- Convention is to use {nameOfAssembly}.Tests
	- In the Tests project, add a reference to the original project solution using a directive
### Test Class
- Requires:
	- the `[TestClass]` attribute decorator
	- Must return void
	- Cannot have parameters
### Challenges with testing UI
- Only public methods can be tests
- All event handlers are private
	- You can make it public, but thats bad practice
- Separation of concerns
	- MVC(Model-View-Controller) - used in web dev
	- MVVM(Model-View-ViewModel) - used in WPF