---
Created: 2024-07-04T18:39
Class: COMP2511
Reviewed: false
---
# Scan sets

- A sequence of characters you want to check for
- entered using %[<CHARACTERS>]

```C
scanf("%10[aeiou]", str);
//reads in up to 10 characters into a char array
//Only allows aeiou as characters; stops scanning when it hits an unallowed character
```

- Inverted scan sets are what you WONT accept, and are designated with a caret inside the square brackets

```C
scanf("%10[^aeiou]", str);
//reads in up to 10 characters into a char array
//Only allows aeiou as characters; stops scanning when it hits an unallowed character
```

# Suppression

- Using * (Assignment Suppression Character) allows you to skip a character between inputs
- using this with %c allows you to discard characters from the input stream

```C
scanf("%d%*c%d%*c%d", &month, &day, &year);
```