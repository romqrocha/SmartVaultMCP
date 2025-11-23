---
Created: 2024-06-24T18:45
Class: COMP2511
Reviewed: false
---
- Any function with a static local variable is **Not** thread safe
- A function is **reenterent** if a function is the same every time you enter it
- strtod → Converts string to double
- strtol → Converts string to long
- strtoul → Converts string to unsigned long
    - These can all read as decimal, octal, or hex based on what was inputted
    - 567 would be read as decimal
    - 0567 is read as octal
    - 0x567 is read as hex
- Pointers-to-pointers are useful when you need to change what a pointer points to
- putchar outputs a single char

  

- sscanf from an array of char instead of directly from the keyboard
- fscanf reads from a file instead of from the keyboard
- sprintf prints directly to a string instead of the terminal
- fprintf prints to a file instead of the terminal
- Each of these have the same options and work the same under the hood
- strchr searches a string for a character; returns a null pointer if it is not found
- strpbrk finds what character in string 2 occurs in string 1
- strrchr finds the rest of the string, starting with the given character
- strspn returns how many characters we go through until find a character that ISNT in str1
- strstr searches for a substring within a string, and returns the address that starts with the substring
- strtok **tokenizes** the string, breaking it apart into smaller substrings.
    - You should give it the string you want to tokenize, and a string containing the separator characters the first time you call it. On each subsequent call you should pass it null for the string to tokenize to get the tokens back.
    - This will edit the string, and add null characters. If you need the original string, you should copy it.

# Recursion

- When used correctly, will automatically give you a stack
- While not performant, many compilers have ‘tail call elimination’, which converts recursive functions into loops if they’re the last call in a function
- Anything you can solve recursively you can solve non-recursively, but may require you to implement your own stack.

# Memory Functions

- Because these functions deal with chunks of memory, they can use void *
- They all also return pointers to void, so we need to cast to convert them to the appropriate data type.
- memcpy
    - Copies n bytes from 1 location to another, then returns a pointer to the new memory location
- memmove
    - as above but handles overlaps in memory locations; for example, if you want to move chars within a string.
- memcmp
    - Compares two chunks of memory; returns 0 if equal, or a +/- value if different
- memchr
    - locations the first occurrence of an **unsigned** char in a chunk; returns a pointer or NULL
- memset
    - writes an **unsigned** char into a chunk, then returns a pointer