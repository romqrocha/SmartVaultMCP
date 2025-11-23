---
tags:
  - OOP
  - Python
---
# Mutability in Python
## Immutable Types
- int
- float
- complex
- str
- tuple
- bytes
- frozenset

- "Assignment is not mutability/mutation"

# Sequence Types
- Probably the thing python is most famous for
- Generic term for an ordered set
## Lists
- Most flexible of them all
- Mutable
	- Operations will change the original list!
- Can add new values
- Can contain multiple types at once
- Declared with square brackets `list:List = ["a", 10]`
- Each item in a list is called an element
- Ordered and indexed, like arrays in other languages
- Can contain other lists `list = ["a", [99, 70, 65], 'P', 12.3]`
- You can get items from the back of the list using negative indices`list[-1]`
## Tuples
- Immutable
- Created with () `myTuple = (1, 2, 3)`
## Common operations
- in `x in someList`
	- Checks if a value is in the sequence
- not in `x not in someList`
	- Inverse of in
- len `len(someList)`
	- gets the length of the sequence
- min
- max
- count
- pop
- remove
- reverse
- append
- clear
- copy
- del

# Dictionaries
- Key: Value pairs
- defined with {} `myDict = {'name': 'Some Name'}`
- Keys should be unique and must be immutable
- Keys do not need to be the same type, either
- Add a new value by assigning a value to the key `myDict['age'] = 33`

# Iteration and Views
- a Virtual Sequence, like a range object
- dict.keys, dict.values, and dict.items return views
- It lets you look at the contents of a dictionary without the extra noise of the other types
- Cant modify a dictionary through the view
- Used primarily for looping
- It changes when the dictionary changes