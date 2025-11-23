---
tags:
  - DesignPattern
---
- Create multiple groups of related objects without specifying their concrete classes
- Each factory creates a *group* of related product that are compatible with each other
- If you find yourself making a table, you probably want an Abstract Factory
![[AbstractFactory_Families.png]]
- Unlike a factory, which makes one product, an Abstract Factory can make all the types of products within the family.
![[AbstractFactory_Generic.png]]
# Advantages
- Ensures families of related objects can all work together
- Useful the the exact number of families are unknown and you need to add new ones in the future
- Adheres to:
	- [[Single Responsibility Principle]]
	- [[Open Closed Principle]]
	- [[Liskov's Substitution Principle]]
	- [[Dependency Inversion Principle]]
# Disadvantages
- A lot of extra classes
	- Makes the codebase complex
	- Makes debugging difficult
- Classes can feel artificial
	- May need to create a whole ew subclass for very minor changes in the creation process