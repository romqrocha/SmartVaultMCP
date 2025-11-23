-`iter()` contains a `next()` method that returns the next generated value
- Iterators *Stream* the contents of a container
	- This makes them more memory efficient
- Throws a `StopIteration` exception when it runs out of items
- `for x in y` auto generates/calls an iterator
- containers have build in iterators

# Variable List Arguments
 - add an asterisk in front of the parameter list to make a variable length list
   `def func(*args)`
- called 'packing'
	- Puts the arguments into a tuples
- You can also 'unpack' a container
 ```
def func(in_str, in_int, in_dict)
	 ...

my_list = ["Str", 5, {"hello":"world"}]
func(*my_list)
 ```
 - `**kwargs` behaves like a dictionary
	 - Key is the keyword
	 - value is the value passed in
	 - If you pass kwargs to another function, and kwargs has keys that match arguments for that function, it will extract those keys and apply them to those arguments.

# Multiple Inheritance
- Python lets you inherit from more than 1 base class
	- Weirdly, Python considers interfaces Classes, so composition and inheritance are basically the same thing.
- If you don't need it, don't use it.
## MRO - Method Resolution Order
- If multiple parents have a method of the same name, python decides a linear order of parents to call- `method resolution order`
	- It generally goes left-to-right through the list of inherited classes and puts them in a stack.
	- You can see the compressed inheritance order is by using `subclass.mro()`
	- Method Resolution Order is also called "Linearization"
### Rules
- Must respect Monotonicity
	- if B precedes A in the in the Linearization of C, then B HAS TO precede A in the Linearization of any child class C
	- tl;dr: A class must respect its parents inheritance
- `L(Z) = [Z] + merge(L(K1), L(K2), L(K3), [K1, K2, K3]`

## Mixins
- Pythons silly way of inheriting interfaces.
- Rather than inheriting all features of a class, just implement their features.
## Alternatives
1) Interface Segregation
2) Use composition instead.
3) Just don't.