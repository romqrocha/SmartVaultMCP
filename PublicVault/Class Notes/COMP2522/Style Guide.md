---
tags:
  - Java
Class: COMP2522
---
# Conventions
- Instance variables are private
- Most instance variables are final
- Always use clear names for data and methods
- Always include units in variable names (eg. lengthCm)
- Do not name Booleans as verbs( isTrained() ), name them as adjectives(trained) that can then be retrieved with a getter( isTrained() )
- Open and close braces are on their own line
- try/catch on newline
- 
## JavaDoc
- Classes:
	- Description
	- @author
	- @version
- Methods:
	- Description
	- @param tags
	- @return tag
	- @throws tag
- JavaDoc the following:
	- Class
	- non-private constants
	- non-private constructors
	- non-private methods
- Use private static validation methods
- Use constructor chaining to avoid code duplication
- Order:
	1) Static Variables and Constants
	2) Instance Variables
	3) Constructors
	4) Setters and Getters
	5) Other methods