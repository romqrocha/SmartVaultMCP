---
Created: 2024-07-01T18:41
Class: COMP2511
Reviewed: false
---
Formatted I/O

Printf

Printing Ints

Printing Floats

Printing Strings and Characters

Other specifiers

Widths

Precision

Combining

Format Flags

Printing Literals and Escape sequences

ScanF

Conversion Specifiers

# Formatted I/O

- s* means read/write from a string
- f* means read/write to a file
- e.g. sscanf scan from string, fscanf reads from file

  

- All i/o operations are performed with a flow of bytes called a **stream**
- a Stream is data flowing into main memory from any device, such as a hard drive, network connection, or keyboard
- On startup, your program has access to
    - Standard Input
    - Standard Output
    - Standard Error

## Printf

- Every call contains a **format control string** that describes how the output is to be formatted
- Control string contains
    - Conversion specifiers
    - Flags
    - Widths
    - Precisions
    - Literals

### Printing Ints

|   |   |
|---|---|
|d|decimal|
|i|decimal|
|o|unsigned octal|
|u|unsigned decimal|
|x or X|unsigned hex|
|h, l, ll(ell ell)|modifiers for if the value is a **shot**, **long** or **long long**|

- Plus signs (+) do not print by default, since default value is positive

### Printing Floats

|   |   |
|---|---|
|e or E|Exponential Notation|
|f or F|Fixed-point notation|
|g or G|F or E, based on values magnitude|
|L|Indicates you want a long-double|

- Default 6 digits of precision to the decimals right
- F will always print at least 1 digit to the left of the decimal
- G will always have no trailing zeros
- for G, precision includes the leading number before the decimal point

### Printing Strings and Characters

|   |   |
|---|---|
|c|char|
|s|string|

- s expects the string to be null terminated
    - If its not, behavior is undefined
    - may crash with “Segmentation Fault” or “Access Violation” error
- s requires a pointer to char (char * )
- Most compilers do not catch format control string errors
    - using %c to print a string, for example

### Other specifiers

|   |   |
|---|---|
|p|pointer|
|%|Percent character(%)|

### Widths

- If width is larger than the value, then the value is **right-aligned**
    - If larger, than it doesn’t truncate and ruin your alignment
- The width is inserted between the % and the conversion specifier

```C
%4d
// the 4 means the width is 4 spaces
```

### Precision

- Different based on type
    - Integer indicates minimum number of digits to print
        - If few digits are to be printed than precision, leading 0’s are added
    - e/E/f indicates the number of digits after decimal
    - g/G indicates maximum number of significant digits to print
    - s indicates the number of characters to print

### Combining

- To use precision, place a decimal (.) followed by an integer between percent and conversion spec

```C
%.3d
```

- Width and precision can be combined

```C
%5.4d
```

- You can use an * to insert a value into the f string

```C
printf("%*.*d", 7, 2, 98.736)
```

- This example may not look useful, but you can calculate the width/precision using calculations and store them in variables to ensure your data always looks correct

### Format Flags

|   |   |
|---|---|
|- (minus sign)|Left-aligns the output within the field|
|+|Displays a plus sign preceding positive values, and a minus sign preceding negative values|
|SPACE (” “)(Literally a space, don’t overthink this)|Prints a space before positive value not printed with the space flag|
|#|Prefix 0 to the output value when used with Octal|
||Prefix 0x or 0X when used with Hexadecimal value|
||Force a decimal point for floating point, even with there are no fractional parts|
|0|Pad with trailing zeros, instead of spaces|

- Flags are placed immediately to the right of the % and before format specifiers

## Printing Literals and Escape sequences

- Certain characters can be escaped by adding a \ before the character

  

## ScanF

- Although you can use this to extract multiple inputs in a single prompt, you should avoid asking the user to enter many data items in response to a single prompt
    - This also means you don’t have the user enter 10 items, have 1 random one be wrong, and have the user re-enter all 10 items again
- Always consider what the user and program will do when incorrect data is entered

### Conversion Specifiers

|   |   |
|---|---|
|d|signed decimal int|
|i|decimal, oct, or hex; detects oct by a leading 0, and hex by leading 0x|
|o|octal|
|u|unsigned decimal int|
|x or X|hex int|
|h, l, ll|short, long, long long|
|e, E, f, g, G|floating point values|
|l or L|floating point long-double|
|s|a single character|
|c|a string|
|p|pointer|
|n|the number of characters input so far|
|%|skip a % in the input|