---
Class: COMP2522
---


Java has 5 types
1. Class
2. Interface
3. Record
4. Enum
5. Annotation`

What are the default data types of Java?
1. int
2. double
3. boolean
4. char

static vs final:

| Static                 | Final                      |
| ---------------------- | -------------------------- |
| Static memory location | Stored value cannot change |
| Belongs to the class   |                            |


args in PSVM should always be final
All arguments to all constructors and methods **must** be final

Most variables should also be final

Declare variables in line, and all variables in 1 chunk
Initialize a separate line.

Include units in names
- weightKg
- firstName

# Class
- •A Java class is a file that describes the data and behaviors of some general category
- use PascalCase for class names
- Data is know as Instance Variables; ak fields, attributes, or properties
- Behaviors are known as Methods; aka functions, procedures
## Methods in a class
- A class has, in this order:
	1) Static Variables and Constants
	2) Instance Variables
	3) Constructors
	4) Setters and Getters
	5) Other methods

# Constants
Data that is both static AND final is a "symbolic constant"

should be named with CONSTANT_CASE

This is a good way to avoid magic numbers

# Static Methods
You can use static methods without instancing a class


A static methods **cannot** call non-static methods or variables
Instance data and methods **can** call static methods and data.

# Comments
About 1/3 of code should be comments
Use first like a plan
```Java
//Inline comment.

/* Multiline comments */

/** JavaDoc - required for non-private entities */
```

# Package

A package is a group(or folder!) of related classes


Naming conventions of a class:
1) Lowercase
2) Reverse domain name
3) meaningful
4) unique

# Visibility/Access
1) package: 
	- Access is limited to the package
2) private: 
	 - Access is limited to ONLY THIS CLASS
3) Protected: 
	- Access is given to all child classes, and classes in the same package
	- ONLY USE FOR METHODS, IF AT ALL
	- NEVER USE FOR DATA
4) public:
	- Access is given to code from anywhere
# Constructor
- Looks like a method, BUT ITS NOT
- Is called automatically when the "new" keyword is used.
- Has the same name as the class
- Its job is to validate the the initialization data or throw an exception
## Instance Initializer block
- A code block in { } before the constructor
- Used when you have a block of code that needs to be initialized for multiple constructors
- Rarely used, since its hard to see and not clear.
## Static initializer block
- like above, but with the static keyword before
```
class Something
{

	static
	{
		...
	}
}
```
- Runs when the class is loaded into memory for the first time.
- Can be used to set up complex logic or data, such as exception handling in static variables and API calls.
## Validation Methods
- A constructors main job is to initialize objects with valid initial states

- validation methods should be private and static
- This means its impossible to change, so its safe and cannot be overridden 
- You can AND SHOULD call these from constructors and mutators
- All they need to do is throw Exceptions with bad data values
```java
private static void validateFirstName(final String firstName)
{
	if (firstName == null)
	{
		thow new IllegalArgumentException(
			"Invalid First Name: " + firstName
		);
	}
}
```
## Constructor Chaining
- this refers to (literally an address reference) the current object
- this() calls another constructor
- This lets you avoid code duplication
```java
class BankAccount
{
    private double balanceCad;
    private int    pin;
    private final String accountNumber;

    private static final int    MIN_PIN_VALUE   = 0;
    private static final int    MAX_PIN_VALUE   = 9999;
    private static final int    ACCT_NUM_LEN    = 6;
    private static final double MIN_BALANCE_CAD = 0.00;
    private static final double DEFAULT_BALANCE_CAD = 0.00;
    private static final int DEFAULT_PIN = 0000;

    BankAccount(final String accountNumber,
                final double balanceCad,
                final int    pin)
    {
        validateAccountNumber(accountNumber);
        validateBalanceCad(balanceCad);
        validatePin(pin);

        this.accountNumber = accountNumber;
        this.balanceCad    = balanceCad;
        this.pin           = pin;
    }

    BankAccount(final String accountNumber, final double balanceCad)
    {
        this(accountNumber, balanceCad, DEFAULT_PIN);
    }

    BankAccount(final String accountNumber,
                final int pin)
    {
        this(accountNumber, DEFAULT_BALANCE_CAD, pin);
    }
```

## Overloading
- The same method/constructor, different argument types or order of arguments
# String Comparison
- positive if 1 is larger than 2
- negative is 1 is smaller than 2
- 0 if 1 and 2 are equal
	- Its literally just 1 subtracted by 2