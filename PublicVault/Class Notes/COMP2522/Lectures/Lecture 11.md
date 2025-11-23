# Final Exam Topics - Similar to quizzes
## Scanner
- open
- close
- get input
## Random
- Get a random int
## Files/Path
- Does a file exist
- Create a file
- Create a directory
- Files is a class with static methods
	- Files.createDirectories();
		- is a safe way to create folders AND subfolders when dealing with complex file structures
	- 
## Streaming/filtering
- Processes collections in a functional way **without** modifying the underlying collection
- Uses sequences of operations instead of loops and if statements
- **Intermediate Operations** transform one stream into a different stream
	- Are "Lazy", so they aren't run until a terminal operation is executed/invoked
- **Terminal Operation** Consumes the Stream so it cant be used after the operation
	- Produces a size effective, such as a new list or a print statement.
- Example:
```java
List<String> wordsWithA = new ArrayList<>();
for (String word : words) 
{
	if (word.startsWith("a")) 
		{ 
			wordsWithA.add(word.toUpperCase()); 
		}
	 }
 }
//as a stream
words.stream()
	.filter(word -> word.startsWith("a"))
	.map(String::toUpperCase)
	.toList();

```
## GUI
- Same requirements as the quiz
## Unit Testing/TDD
- 
## Design Patterns
- Singleton
	- Make constructor private
	- use getInstance() to return the class, or create one if it doesnt exist
- Command
	- Listeners wait for a signal, then do a thing when they receive the signal
- Factory
- AbstractFactory
- Decorator
	- 
- Observer
	- Inverse of Command, object wait for another object to do a thing, then adjust accordingly
- 
## Concurrency
- What is it
- What does it solve?
- What problems does it create?
# Concurrency
- 