---
Class: COMP2522
Created: "[[2024 11 13]]"
tags:
  - OOP
  - Java
Reviewed: false
---
# Test Driven Development
1. Record meetings with potential clients/target audience
2. Transcribe into paragraphs/stories
3. Make the stories into checklist items
	- These turn into requirements
		- Runs on Ipad
		- Runs on IPhone
		- IOS Version 16+
		- No network connection
			- Show company logo and prompts to connect to wifi
		- When network connection is established, login
		- etc.
4. Each checklist item becomes a unit test
5. Write the code last

# Junit tests
- Tests require at least 2 objects set up in Before
- Set objects to null in After
- assertTrue and assertFalse are bad
	- use assertEquals and assertNotEquals

## Positive Tests
- Testing you get the expected results on an operation
- e.g.
	- Testing if the correct assert it thrown
	- Testing if you can enter specific args to a class
## Boundary Tests
- Tests the min/max values allowed within a class
- e.g.
	- Passing in the max value
	- passing in a string of max length

## Negative Tests
- Expecting things break where and how you plan