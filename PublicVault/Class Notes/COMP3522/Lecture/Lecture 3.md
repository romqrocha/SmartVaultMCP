---
tags:
  - OOP
  - Python
Reviewed: false
---
# Time handling
- `time.time()` returns the number of seconds since January 01, 1970
- `time.sleep()` blocks code execution for the given number of seconds
	- Can take in a float for extra precision
- `datetime.fromtimestamp()` takes a Unix timestamp and returns a human-readable date 
- `datetime.timedelta` represents the difference between two datetimes

# Visibility
- No access or visibility modifiers
- Single underscore is used to hide the variable `_x`
	- Still appears in docstrings
- Double underscore is used to make it hard to access `__x`
	- Signals its private
	- Remove inheritance from that variable
	- Allows it to not be accessed
	- throws an error

# Dunders
## `__repr__`
- Raw data, not prettied up 
- Used for developers
## `__str__`
- Cleaned up data
- Given to users

# Accessors/Mutators
- Literally just getters/setters
- Accessors:
	- Only have self
	- Must not modify or print or send messages
- Mutators
	- May only modify a single value, and only if it remains logical

## Properties
- Use `@property` decorator to create a new property from a function
  ``` python
    @property
    def x(self): # creates an X property
	```
- Then use `x.setter` or `x.getter` to set the getters/setters of that property
  ```python
	@x.setter
	def x(self, new):
		...
	@x.getter
	def x(self):
		...
	```