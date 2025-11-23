---
tags:
  - Python
---
# Iterator and Iterable
- Iterable can be iterated
- Iterator goes through the elements of an Iterable
- To make a custom class iterator, overide the `__next__()` and `__iter__()`
- To make a custom iterable, implement `__iter__()`
- `__iter__()` must return an iterator

# Comprehensions
## List
`[f(x) if condition else g(x) for x in some_iterable`
`[val.method() if comp else val.method2() for val in container`
`[Output for variable in list if condition]`
- if there's only an if, it goes to the right
- if theres an if/else, it goes to the left
### Challenges
`[chr(i+65) for i in range(0, 26)]`
`[x for x in range(0, 10) if x%2 == 0]`
`[x if x%2==0 else 'x' for x in range(0, 10)]`

## Dictionary
`{f:key: g(value) for key, value in some iterable if conditional}`
- Make sure you use `dict.items()` when iterating through key/value pairs to unpack them

## Why use them?
- Hide the working of iterators
- Uses iterators for complex operations
- Faster
- arguably more readable

![[Event Driven Programming]]
![[Observer Design Pattern]]