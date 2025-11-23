# Solid Design Principles
- Stands for 
	- [[Single Responsibility Principle]]
	- [[Open Closed Principle]]
	- [[Liskov's Substitution Principle]]
	- [[Interface Segregation Principle]]
	- [[Dependency Inversion Principle]]
	- Often includes [[Law of Demeter]] as well
## Dependencies
- Entity A uses Entity B
## Coupling
- A is so dependent on B that even if you were to change B with something similar, A would need to be refactored
- We can reduce coupling and direct dependencies with interfaces that require other classes to implement the features we need