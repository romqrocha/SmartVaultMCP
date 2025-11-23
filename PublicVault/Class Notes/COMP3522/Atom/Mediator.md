# Mediator
> [!note] 
> Reduces the number of dependencies between a large number of components of a system
- A [[Behavior Design Pattern]]
- Restricts communication between different components by introducing a middleperson to "Mediate" communication between them
	- Think about **Controller Classes**
	- Generally a controller talks to components, but the components do not talk to the controller
	- In Mediator, the communication is bi-directional
![[DesignPattern_MediatorUML.png]]
## Disadvantages
- Becomes an epicenter for coupling