# Friend Keyword
- Friends can access private members
	- Can be offered to a global function, member function, or an entire class
- Is not reciprocal
- Does not extend
	- A friend of a friend is not a friend
```cpp
#include <iostream>
using namespace std;

class Count {
   friend void setX(Count&, int); // friend declaration
   // friend int Abc::method(Count &); // offers friendship to the method Abc::method()
   // friend class Abc; // offers friendship to all of the methods of the Abc class

public:
   int getX() const { return x; }

private:
   int x{0}; 
};

// function setX can modify private data of Count         
// because setX is declared as a friend of Count (line 8)
void setX(Count& c, int val) {
   c.x = val; // allowed because setX is a friend of Count
}
```
# Inheritance
- Member constructors completes before the class constructor
- Base class constructors completes before derived class constructors
1. Base Members
2. Base Class
3. Derived Members
4. Derived Class
# ABC
- Two ways
1. One or more pure virtual methods
	- The “ =0 ” is a pure specifier; `virtual void doThing() = 0;`
2. Inherit from an ABC and don't override all the pure virtual method
- Can't instantiate, can declare references and pointers to.
# Textbook sections
[[Paul J. Deitel, Harvey Deitel - C++ How to Program-Pearson (2016).pdf#page=794&selection=0,5,0,23|Function Templates]]
[[Paul J. Deitel, Harvey Deitel - C++ How to Program-Pearson (2016).pdf#page=1184&selection=0,0,0,19|Dot and Arrow operators]]
[[Paul J. Deitel, Harvey Deitel - C++ How to Program-Pearson (2016).pdf#page=1237&selection=1,1,2,6|Friend function and classes]]
[[Paul J. Deitel, Harvey Deitel - C++ How to Program-Pearson (2016).pdf#page=1242&selection=0,14,4,7|this pointer]]
[[Paul J. Deitel, Harvey Deitel - C++ How to Program-Pearson (2016).pdf#page=1563&selection=0,34,1,11|Virtual functions]]
[[Paul J. Deitel, Harvey Deitel - C++ How to Program-Pearson (2016).pdf#page=1585&selection=0,30,4,9|Abstract classes and Pure Virtual functions]]
