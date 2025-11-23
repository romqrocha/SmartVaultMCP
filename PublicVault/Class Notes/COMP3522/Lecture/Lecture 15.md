# True parallel
- In python, we need to make new processes to get true parallelism
	- Each instance has its own interpreter, and thus its own GIL
- You can do this with the `multiprocessing` library
```python
def my_func():
	print(foo)

p1 = multiprocessing.Process(target=my_func)
p1.start()
p1.join()
```
- You can also use a pool to create reusable workers
```python
with multiprocessing.Pool(processes=3) as pool:  
	pool.map(
		countdown,
		[param_func_1,
		 param_func_2,
		 param_func_3]
	)
```
![[Multiprocessing]]

# Lazy Initialization
- AKA Lazy Loading
- is a [[Creational Design Pattern]]
- Delay creation of an expensive or heavy resource until its actually needed.
## Advantages
- Dedicate resources on-demand
- speed up execution when not accessing expensive resources
## Disadvantage
- Not a good choice if the object needs to be initialized every time it is access
	- Especially if it is accessed frequently

# Builder
> [!note] Allows us to break the construction code into a separate class
- A separate class that allows you to set arguments and parameters via arguments
![[BuilderSlide.png]]
![[DesignPattern_Builder_UML.png]]
## Director
- A class that is responsible for building pre-sets using a builder
![[DesignPattern_Director.png]]
![[DesignPattern_Director_UML.png]]
## Advantages
- Gets rid of large, ugly initialization methods
- Allows products to be mixed and matched
- [[Single Responsibility Principle]] since we decouple construction logic from product
## Disadvantages
- Code complexity increases as we introduce more classes
- Doesn't work for products that cant be broken down into independent parts
- 