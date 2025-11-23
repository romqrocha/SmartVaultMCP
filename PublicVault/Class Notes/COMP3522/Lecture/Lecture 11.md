---
tags:
  - Python
---
# Generators
- Special iterator
- Uses `yield` to return the next element
- Any function with `yield` is a generator
	- `yield` is a special `return`
	- Functions are objects so a reference to the generator must be kept
	- The first call creates the generator object
	- Get the next value with a `next()` call
	- example: 
	```python
	gen_ref = my_generator()
	print(next(gen_ref))
	```
## Generator Expressions
- inline generator, like list comprehension
- use `(..)` instead of `[..]`
- `(f(x) for x in some_iterable if condition)`
- You can use this to create infinite generators
- Considered less flexible than a generator function(because its not reusable)
	- Wrap in a function to make it reusable
```python
def warning_filter_generator(file_object):  
	#one line with generator expression!  
	yield from (line for line in file_object if '[Warning]' in line)  
	
with open("log_file.txt", mode='r', encoding='utf-8') as log_file:  
	filter = warning_filter_generator(log_file)  
	for warning_line in filter:  
		print(warning_line)
```
# Lambda
- Syntax: `lambda parameters: expression`
- `lambda x: x * 5` would take 1 argument and return x * 5
- `lam: Callable[[int], int = lambda x: x * 5` would be how you annotate it.
	- Don't do this, it's against pep8
- Lambdas can't/shouldn't be multiline

# Map
- Built in function for list comprehension
- Takes a function and applies that function to every element in an `iterable`
`map(function, iterable)`
```python
a = map(int, [1.2, 2.5, 3.7, 4.6])
```
- `map` returns a Map object, which is a generator type
- You can use `list()` on it to get all the values
```python
print(list(a))
```
- map can also handle multiple arguments with the function
```python
first_names = ["Ross", "Rachel", "Pheobe", "Chandler", "Monica","Joey"]  
last_names = ["Geller", "Green", "Buffay", "Bing", "Geller","Tribbiani"]  
full_names_map = map(lambda x, y: f"{x} {y}", first_names, last_names)  
print(type(full_names_map)) 
print(tuple(full_names_map))
```
# Filter
- Like map, but must return true or false
- Creates a new collection of items that MATCH the filters TRUE value