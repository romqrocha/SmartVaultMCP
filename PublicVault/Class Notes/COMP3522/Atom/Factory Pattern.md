---
tags:
  - DesignPattern
---
- Used when you want to separate creation code from the code that uses the object
- 'Factory' can mean:
	- The design patterns
	- A class that create objects
	- A static/class method that generates objects
- Be sure to be specific when discussing "Factory" vs "Factory Pattern"
- Tied to [[Dependency Inversion Principle]]
	- e.g. A Logistics system doesn't care how the goods are transported, just that the concrete implementations can `deliver()` the goods.
- We create a class to instantiate objects that implement interfaces or abstract base classes
- You can also have a Factory that just returns more specific factories
	- e.g. a `TransportFactory` might return a `TruckFactory` or a `ShipFactory`
	![[FactoryPattern_Generic.png]]
# Advantages
- Adheres to:
	- [[Single Responsibility Principle]]
	- [[Open Closed Principle]]
	- [[Liskov's Substitution Principle]]
	- [[Dependency Inversion Principle]]
- Separates and encapsulates creation logic
- Provides an interface for object creation
- Use when exact types and dependencies of the objects you need are either unknown, or susceptible to change
	- When you add a new product, just create a new factory for it and it should be plug-and-play!
# Disadvantages
- A lot of extra classes
	- Makes the codebase complex
	- Makes debugging difficult
- Classes can feel artificial
	- May need to create a whole ew subclass for very minor changes in the creation process