---
Created: 2024-01-24T13:39
Class: Comp1510
Reviewed: false
tags:
  - Java
---
# Scanner
You cannot have a String variable in Java. String is a class, so you can only have a String Reference
# String
Strings are **IMMUTABLE** - they cannot change.  
When you concat 2 strings, you don’t change a string, you create a new one.  

String.substring(a, b) returns a number of characters back that equals to b-a

e.g. - String.substring(3, 30) returns 30-3, or 27, characters

# Packages
Classes are organized into Packages

Name of a class is `[Package Name].[Class Name]` - e.g. the String class is `java.lang.String` Package, Scanner class is `java.util.Scanner`

You can use a **fully qualified name** when you want a package - java.util.Scanner

- java.util.Scanner scan = new Java.util.Scanner(System.in);

or you can Import it to shorten how you use it in the future

- Import java.util.Scanner;
- Scanner scan = new Scanner(System.in);

You can do this for ALL classes in a package with a *

- import java.util.*;
- Scanner scan = new Scanner(System.in);

**This is bad practice** - you’ll have TONS of class names you don’t need

To make your own package, set it in the first line of a class

- package mypackagename;
- package q1;
- package ca.bcit.infosys.servletutils;

Your classes **MUST** be in a folder with the path of your package name

./mypackagename/class.java

./q1/class.java

./ca/bcit/infosys/servleutils/class.java

Your code **CAN** work without a package, Java creates a default package for you

**This is bad practice**- get in the habit of packaging your stuff
# Random

Computers are REALLY bad at being random, technically impossible

Really good at being deterministic

java.util.Random is **PSEUDORANDOM** - it performs complicated formulas to an initial input to **seem** random.

There are better randomness algorithms, and packages in Java to support those, but Random is generally **good enough.**

  

Labeling is easy: It means putting a string before an output to say what it.

- “The number you input is: “ + num1;
- ^The label ^input/output

Floats are inaccurate, and shouldnt be used for precision, like banking

- Java has an entire LongDecimal class that handles currency, for example

  

Math class methods are STATIC, they dont need an object, and are invoked with Math.[method name]()

You can import them using a “import static java.lang.Math.[method]” so you can avoid typing Math.[method] all the time

# Formatting

- NumberFormat and DecimalFormat
- NumberFormat formats as currency or percentages
- DecimalFormat formats based on a given pattern
- Both are in the java.text library
- NumberFormat has static methods that return a formatter, DO NOT USE NEW
- NumberFormat.getCurrencyInstance()
    - Currency formatter formats the currency symbol and replaces the decimal point with the local version
- NumberFormat.getPercentInstance()
    - Uses a series of characters to define what it shows
    - e.g. - “#,#\#0.##”
        - “#” means to show a number in that space, if the number is long enough
        - “,” forces commas to be placed between digits
        - 0 means to show a 0 if there isn’t a valid number
- To get a formatted string, you can use the format(string) method from your formatter object

# Enums

- Allows us to create a variable that can only be set to a specific list of values
    - e.g. - enum Season {winter, spring, summer, fall};
- enums are a type of **Class** so we should name them appropriately
- All references for the values in the enum are **Aliases**, and values are immutable
- Each value needs a javadoc comment
- Can be referenced like a list [0, 1, 2, 3]
    - This is called the ORDINAL value
- ordinal method returns the ordinal value of the currently set value
- name method returns an immutable string that is the name of the value
- toString method returns a mutable string, for use with formatters and etc. This is the same as just calling the object in a string concatenation.

# Wrapper Classes

- For each of the primitive types, there is a class

|   |   |
|---|---|
|Primitive|Wrapper|
|byte|Byte|
|short|Short|
|int|Int|
|long|Long|
|float|Float|
|double|Double|
|char|Character|
|boolean|Boolean|

- Wrapped Classes allow for methods associated with the type, as well as Static methods and Constants.
    - e.g. Integer contains parseInt(str) method
        - Takes a string that represents an int and converts it
    - classes also contain MIN_VALUE and MAX_VALUE constants.
- Are known to be slow when overused
- Values assigned to Wrapper Classes are immutable.
- Taking a primitive and wrapping it is called “boxing”. Taking a Wrapped value and assigning it to a primitive is called “Unboxing”.
    - Collectively called ‘Autoboxing’
- Some Java ‘containers’ can only hold objects or references, so the Wrapper is required to use those with primitive values.