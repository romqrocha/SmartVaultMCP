# Lab 6
Exercises 13.3 (1,3,9,10,11,12,14 and 24) and13.4

Exercise 17.1 to 17.6, 17.8 and 17.9. 

The text provides solutions for all of these exercises.

You can submit your solution in the same format as the solutions are displayed in the text.
# Lecture

# Exception Handling
- Expensive; slows the program down
	- Should be thrown "once in a blue moon"
	- Used for something actually exceptional
## C++
- In `stdexcept`
- Always catch by reference
- Use the caught object's `.what()` method to get the details
- You can rethrow the caught exception within a catch block by simply calling `throw;` within a catch block - see [[fig17_03_Rethrowing_an_exception]]
- If your function doesn't throw an exception, you should add `noexcept` after the parameter list in both the prototype and definition.
	- If its a const function, you can do `const noexcept`
- You can also catch all types of exception with `catch(...)`
	- Typically the last catch, as a last resort
	- You should never actually expect this to be executed; like a default in a switch statement.
- You can set a new handler for **failed memory allocations** by making a prototype with `void customNewHandler()`
	- Note return type of void, no arguments
	- include `<new>`
	- use `set_new_handler(customNewHandler)` to set a custom handler.
# Smart Pointers