---
Created: 2024-03-04T15:37
Class: Comp1510
Reviewed: false
tags:
  - Java
---
- All loops should only have one input, and one output.
    - Bruce claims Break and Continue are evil and bad because of it.

# Switch Statement

- evaluates an expression, then attempts to match to one of possible _cases._
- Each _case_ contains a value and a list of statements that are run if the _case_ is met.
- Is best used for examples where you have finite numbers of possibilities; enums, ints, Strings, and char for example.
    - Floats are a bad choice because of floating point error.
- Flow of control transfers to the **first** value that matches the expression.
- The expression tells you where you **start**, not which one you exclusively run.

```Java
switch ( expression ) {
		case value1 : 
				statement-list;
				break;
		case value2 :
				statement-list2;
				break;
		case value3 :
				statement-list3;
				break;
		case default :
				statement-list4;
				break;
}
```

- In the absence of a break statement, flow will continue down to the next case, which is usually a bug.
- cant do relational checks; only equality. expression = value, not expression > value, or value1 < expression > value 2.

# Conditional (Ternary) Operator

- Evaluates to one of two expressions based on a Boolean condition.
- if condition is true, expression 1 is evaluated, if false expression 2 is evaluated

```Java
condition ? expression1 : expression2
```

- An example of how to use it to handle singular vs plural

```Java
System.out.println(
		"Your change is " 
		+ count 
		+ ((count == 1) ? "Dime" : "Dimes"));
```

```Java
System.out.println(
		"It is " +
		((num > 10) ? "" : "not ")
		+ " greater than 10");
```

  

# Do statement

```Java
do {
	statement-block;
} while (condition);
```

- statement-block is executed once, then condition is evaluated.
- like a while loop, but always executed at least once.

```Java
int count = 0;
do {
	count++;
	System.out.println(count);
} while (count < 5);
```

- Basically a “Do you want to do it again” loop.

# For Loop

- Intended to be a counting loop
- Should be used when you know how many times you’ll be repeating the loop.
- **Well suited for executing statements a specific number of times that can be calculated or determined in advance**
    - If the number of iterations depends on something that happens in the loop, use a while loop.

```Java
for ( initialization ; condition ; in/decrement ) {
		statement;
}
```

- Initialization is executed once **before** the loop begins
- Statement is executed until condition is false.
- Increment/decrement happens before the condition is checked again.

# For-each loops

- Variant of For loop that simplifies the processing of an iterator/iterable object.

```Java
for (Object argName : Iterable/Collection/Array) {
		statement;
}
```

```Java
for (Book myBook : bookList) {
		System.out.println(myBook);
}
```