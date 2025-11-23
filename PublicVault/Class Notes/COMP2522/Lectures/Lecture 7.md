---
Class: COMP2522
Created: '[[2024 10 30]]'
tags: 
Reviewed: false
---
# IO
- New ways to do this use NIO(New IO) and NIO2 classes
## Paths
- Abstracts away the OS
- Always use Paths.get() to construct a path
- Avoid hardcoded separator.
	- System.lineSeparator() is better
	- Paths.get() is best
 ```java
  Paths.get("FolderA", "FolderB", "File.txt")
  ```
## Files
To create folders and files
```java
Files.createPath(path);
Files.createFile(path);
Files.createDirectory(dirPath);
//For nested Directories
Files.createDirectories(Path.get("dir/subdir"));
```


### Writing/Appending to file
```java
Files.write(path, lines, StandardOpenOption.CREATE);
Files.writeString(path, "One string, one line", StandardOpenOption.CREATE);
Files.write(path, lines, StandardOpenOption.CREATE, StandardOpenOption.APPEND);
Files.write(path, lines, StandardOpenOption.APPEND);
```

# Try-With-Resources
```java
try(BufferedReader reader = Files.newBufferedReader(path))
{
	...
}
catch (final IOException e)
{
	e.printStackTrace();
}
```
# Scanner

# Streams
- Works for all collections and arrays
- Also a stream class
- 
- Two types of operations:
	1. Intermediate
		- Reduces the data we can use in later steps
		- filter, map, reduce
		- Filter is particularly useful, since it only allows data that MATCHES the predicate to move on.
	2. Terminal
		- Can do nothing after these operations
		- forEach, returning a new list/collection/array, etc.
	- We will have zero-or-more intermediate operations, then a single Terminal operation
## Terminal Operations
### forEach
- Performs an action on each element in the stream
### toArray
- Converts the elements in a stream to an array
- Useful when you need a fixed-size, indexed collection of elements
### Reduce
- Two types:
	- BinaryOperator
		- Just means "Two inputs" - a vs b
	- Identity, BinaryOperator 
		- Identity is a starting value
###  collect()
-  Collects the elements of a stream into a collection or other data structure
## Intermediate Operations
### filter()
- it **keeps** things that meet the given criteria
- 
# Optional
- A container that may or may not hold a value
- isPresent()
	- Used to check if an optional argument is used
- get()
	- Gets the value so we can assign it. Can only be used after isPresent.