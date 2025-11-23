---
Class: COMP2522
Created: "[[2024 10 02]]"
tags:
  - OOP
Reviewed: false
---
```
import java.util.ArrayList
class spam
{
	private final List<Type> name;
	spam()
	{
		name = new ArrayList<>();
	}
}


```
- System.lineSeparator() can be used to insert a system-specific newline character
# ArrayList

- RAGS
	- Remove
	- Add
	- Get
	- Size

# Generics

Allows us to ensure we only have 1 type of object interacting with


# Iterator
```
java.util.iterator
```
- Usually too complicated to be required over a for-each loop
- Declared as a **local** variable *inside a method*
- Iterator is an interface, not a class
	- Its also a pointer
	- At initialization, it points to the 0th element
	- when you call Next, it increments
- collections have a .iterator() method that return an iterator
```
final interator<String> it;
it = days.iterator();

while it.hasNext();
{
	final String day;
	day = it.next();
	System.out.printlm(day);
}
```
- This is called the "iterator pattern"
- in a foreach loop, you can't use ArrayList.remove(); because you cant alter the ArrayList while processing it
- in an iterator, you can remove items while iterating by Iterator.remove();

# Maps and Sets
## Maps
```
import java.util.Map;
```
- A map is a very efficient way to get access to an individual element
	- using Key/Value pairs
	- Keys and Values cannot be primitive types
	- Keys are unique
	- Non-contiguous
	- Can find items in linear time, so very quick
	- KV pairs are called as "Entry set"
- instead of RAGS, we have Remove, Put, Get, Size
- RPGS
```
private final Map<Integer, String> numbers;

psvm()
{
	numbers = new HashMap<>();
	numbers.put(5, "five");
	numbers.get(5); // returns "five"
}
```

## Sets
- A unordered collection
- No duplicates are allowed
```
private final Map<Integer, String> numbers;
private final Set<Integer> keys;

psvm()
{
	numbers = new HashMap<>();
	numbers.size() //returns the number of items
	numbers.put(5, "five");

	keys = numbers.keySet();

	for(final Integer key: keys)
	{
		System.out.println(key);
	}
}
```

