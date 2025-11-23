# Review week
# SOLID

## **S**ingle responsibility
- Every class is responsible for one thing
## **O**pen closed
- Open for extension
- Closed for modification
## **L**iskov substitution
- If $S$ is a subtype of $T$, then any object of type $T$ can be replace with object of type $S$
	- Its polymorphism. That's all.
## **I**nterface Segregation
- Composition over Inheritance
- Break down generic functionality into common interfaces, then each child can implement specific functionality
## **D**ependency Inversion
- A combination of [[Open Closed Principle]] and [[Liskov's Substitution Principle]]
- We generally compose high-level modules(controllers) that are made of/control low-level modules
- This means the modules are tightly-coupled
- We should instead create abstract classes/interfaces(Liskovs!) that all our low-level modules can inherit from(Open/Close!) and use the same abstract methods from.

## Law of Demeter
- Law of least-responsibility
- You shouldn't have to chain object calls from 

# MRO
- Must respect inheritance of parent
- Must respect own inheritance order
```python
A();
B();
C(A, B);
D(B, A);

L(C) = [C, A, B]
L(D) = [D, B, A]

L(E) = [current_class] + merge(L(parents), [parents]))

L(E) = [E] + merge(L(C), L(D), [C, D]))
L(E) = [E] + merge([C, A, B], [D, B, A], [C, D]))
# First element in the list is the head
# All other are 'a tail'
# Algo: Get head of first list
	# Compare with TAILS of all other lists
	# If its not in the tails of subsequent lists, 
	# Remove it from all lists and append it to current_class
L(E) = [E, C] + merge([A, B], [D, B, A], [D]))
L(E) = [E, C] + merge([A, B], [D, B, A], [D]))
								# ^ A is in a tail
	# See if head of that list exists in subsequent lists
L(E) = [E, C] + merge([A, B], [D, B, A], [D]))
									    #^No tail, only head
L(E) = [E, C, D] + merge([A, B], [B, A])
									# ^ A in tail
									# and no more
									# lists
# Monotonicity failed
```