---
Class: COMP2522
Created: "[[2024 11 20]]"
tags:
  - OOP
  - DesignPattern
Reviewed: false
---
- Behavioral Design pattern
- Turns requests/actions into objects
	- The object encapsulates all information needed to perform an action or trigger an event
- Components:
	- Command Functional Interface
		- Execute()
	- Concrete Command implements Command
	- Invoker
		- Requests the command
	- Receiver
		- Performs the command
- Uses
	- Undo/redo functionality
		- Add a queue of operations you've done, then undo them as needed
	- Queues and Logging
		- Maintains history, eg. a task scheduler
	- Dynamic configuration, like a GUI