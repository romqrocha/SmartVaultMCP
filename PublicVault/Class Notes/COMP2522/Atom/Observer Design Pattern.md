---
Class: COMP2522
Created: "[[2024 11 20]]"
tags:
  - OOP
  - DesignPattern
Reviewed: false
---
- Subject interface
	- Add
	- Remove
	- Notify
- Implement concrete Subject
	- Manages state maintains a list of observers
- Observer Interface
	- Method the subject will use to notify observers when a change occurs
	- Observer shouldn't control the changes within the Subjects
- Implement concrete Observers
![[ObserverDesignPattern.png]]
- We have a Core that has a list of Observers
- Each observer has to have an update method
- When Core calls notify, it loops through its Observer list and calls each of their update methods