---
tags:
  - OOP/SOLID
---
## High Level Modules
- The controllers for your program
- Contain complex logic
## Low Level Modules
- Encapsulates some simple, atomic behavior
	- reading/writing a file
	- display an image
	- etc

- This is bad design, as its tightly coupled
- Instead, make an abstract layer that you can extend with new classes