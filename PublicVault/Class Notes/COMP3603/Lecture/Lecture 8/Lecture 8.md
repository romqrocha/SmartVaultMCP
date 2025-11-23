Chapter 24 - Other C++ 11 features  
1. Chapter 24 slides 7 to 12 inclusive - An introduction to the shared_ptr class  
2. 24_01_03_shared_ptr example  
3. Chapter 24 slides 91 to 96 inclusive - An introduction to move semantics  
4. fig24_12_14_move_semantics_example  
5. Describe the double ended queue students will need to implement for this assignment 6. They will have 2 weeks to complete this assignment.
# Smart Pointers
- [[Pointers]] with additional functionality
- When a smart pointer goes out of scope, the destructor is automatically invoked, same as any object.
# Unique Pointers
#TODO read up on this
# Shared Pointer
- A type of [[Smart Pointer]]
- Uses reference counting to know when to destroy the related object
- When there are no reference to the shared pointer left, it destroys the object and frees the memory
- Useful when multiple pointers to the same resource are needed
- If a resource requires a complex cleanup, you can supply a custom `deleter` function to the shared pointer constructor
# Predicate
- A [[Function]] that returns a [[Boolean]] value.
# Move Semantics
- Rather than destroying temporary objects that are being returned, `C++` moves the object to the memory location for the return instead
# Rule of 3
- A set of functions that should be overloaded for any class that uses dynamically allocated memory:
	- Copy Constructor
	- Destructor
	- Copy Assignment Operator
- As of `C++ 11`, with `rvalue reference`(declared with `&&`) and [[Move Semantics]], it is now the Rule of 5, and should have:
	- Move Constructor`MyClass(MyClass &&) noexcept`
	- Move Assignment`MyClass &operator=(MyClass&&)`
	- 