---
Class: COMP2522
Created: "[[2024 09 25]]"
tags:
  - OOP
Reviewed: false
---
# Review
- Private: Consider if it should be overwritten
- Final: Should it be overridable or extended or change
	- Keep in mind, methods can be final
- Abstract: 
- Static/Instance: Does it belong to the class or the instance
- Class or interface:
![[Interfaces#Interfaces]]
## Overriding concrete methods with the same signature
- Overwrite by using @Overwrite
- return the value from interfaceName.super.funcName
```
@Override
public int min()
{
	return Moveable.super.min()
}
```
- You need the super keyword after the interface name to call a default method from an interface.
# compareTo
- Positive number is this > that
- Negative if that > this
- 0 if this.equals(that)

# Generics
```
<T extends Comparable<T>> T functionName(T argName)
```