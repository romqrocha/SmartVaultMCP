---
Created: 2024-07-18T18:37
Class: COMP2511
Reviewed: false
---
# Data Files

- Can be CRUD by C programs
- Are used for permanent storage of large amounts of data
- C views each files as a sequence of bytes
- End with _end-of-file_ marker
- Opening a file returns a pointer to a stream to a **File** structure
    - stdin, stdout, and stderr are file pointers
- C doesn’t impose any file structure structure
    - Programmer must know how the data is organized
- Create a file

```C
FILE *cfPtr; // Create a file pointer
cfPtr = fopen("clients.txt", "w"); //fopen returns a file pointer, w means write
```

- Sequential Files(Text)

# Sequential Files

|Mode|Description|
|---|---|
|r|Open an _existing_ file for _reading_|
|w|create a file for writing. if the file already exists, discard the current contents|
|a|append; open or create a file for writing at the end of the file|
|r+|Open an existing file for read **and** write|
|w+|Open a file for read and write. If a file exists, discard the content.|
|a+|Append; Open or create a file for read and write; writing is done at the end of the file|

- Read/write in stdlib
    - fgetc
        - Gets a single character from the file
    - fputc
        - writes a character to a file
    - fgets
        - Gets a string from a file
    - fputs
        - writes a string from a file
    - fscanf
        
    - fprintf
        - use to print to a file
    - feof
        - Returns True if EOF indicator is set for the specified file
        - Wont return true if you have tried to read PAST the end of the file
    - fclose
        - Closes the file
        - Performed automatically when the program ends
            - Good practice to do it explicitly
- Remember:
    - Each file must have a unique name, and should have its own pointer
    - You can use rewind(filePtr) to set the read pointer back to the start of the file
- Sequential files cannot be modified without risk of destroying other data.
- Fields can vary in size

# Random Access Files

|Mode|Description|
|---|---|
|rb|open existing for reading|
|wb|create for writing; discard content of existing file|
|ab|append/create file for writing|
|rb+|open existing for read/write|
|wb+|open existing for read/write; discard content of existing file|
|ab+|append/create file for read/write|

- Access individual records without searching through other records
- Instant access to records in a file
- Data can be inserted without destroying other data
- Data can be updated or deleted without overwriting
- Implemented using fixed length records
- Written in ‘unformatted’(Raw bytes)
    - all data of the same type use the same amount of memory
    - The records of the same type have a fixed length
    - Not human readable

|Function|Description|args|
|---|---|---|
|fwrite|transfer bytes from memory to file|1) Location to transfer FROM  <br>2) number of bytes to write  <br>3) For arrays, number of elements to transfer  <br>4) File to write to|
|fread|transfer bytes to memory from a file|1) Location to transfer FROM  <br>2) Number of bytes to read  <br>3) File pointer|
|fseek|positions you where you need to be in a file|1) pointer to a file  <br>2) offset  <br>3)Symbolic Constant  <br>- Seek_Set: Starts at the beginning of the file  <br>- Seek_Cur: Starts at the current location of the file  <br>- Seek_End: Starts at the end of the file|
|ftell|Tells you where you are in the file; returns a long byte pointer||

# Data Hierarchy

- Bits are the smallest unit; 0 or 1
- Byte - 8 bits
    - Used for decimal digits, letters, and special symbols
- Field
    - A group of characters
- Record
    - A group of related fields
    - A _Struct_ in C
- File
    - A group of related Records
- Database
    - A group of related Files

# File structure

- File Descriptor
    - Index into Operating System called the ‘Open File Table’
- File Control Block
    - Found in every array element; system uses it to administer the file