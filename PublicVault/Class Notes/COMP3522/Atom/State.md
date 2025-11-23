- A [[Behavior Design Pattern]]
- Allows for a modular way to add states(values and behaviors) to an object and control transitions
![[DesignPattern_State.png]]
- Not useful with few states, since it requires an additional class for each state
# When to use
- When an objects behavior is heavily dependent on its state, **and** the number of states is large or you may want to add more in the future
- Avoids massive if statement blocks based on state conditions
- You can create hierarchies of state classes if there are a lot of states that share code
- Implements [[Single Responsibility Principle]]
	- Each state is self contained
- Implements [[Open Closed Principle]]
	- Can add and remove states without modifying the context and multiple if-else statements
# Disadvantages
- Can become hard to maintain if the object rarely changes states or has few states
- States can be highly coupled
- Lots of classes and code to maintain.