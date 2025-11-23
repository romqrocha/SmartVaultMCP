To understand what a cryptogram is see:

http://www.cryptograms.org/ for an example of a cryptogram. 

Your program only needs to generate the puzzle, it does not need to be able to solve the puzzle (that is the "fun" part, left for a human to do).

Note that my solution first converts the string to lower case. It is not necessary for you to do the same, but it is probably easier. BTW, my solution only converts the alpha characters.

PLEASE NOTE: The last statement in the text exercise description is: "Use techniques similar to to those in Exercise ...".

THIS IS INCORRECT!!! 

If the letter 'a' is translated to the letter 'm', the letter 'b' would likely not be translated to a 'n' in a valid cryptogram.  Another example is that "abc" would likely not be translated to "xyz" but more likely into something like "xrb". Otherwise the puzzle would be much too simple to solve.  Therefore you can hopefully see that this is not a trivial exercise.  You will need to use some type of random number generation and you will need to keep track of which letters have been used and which are still free to be used. To understand better, execute one of the .exe I provided with the input string "ABC ABC" (minus the quotes).

BTW, solving a cryptogram would be very difficult to program. The program would need access to a dictionary and have some information on the statistical frequency of letters and possibly a list of common phrases and/or expressions as well. This is why you will not see as an exercise in this chapter "write a program to solve a cryptogram without human assistance". That would be a very challenging exercise requiring sophisticated AI techniques.