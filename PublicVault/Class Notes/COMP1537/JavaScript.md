---
Created: 2024-02-01T13:52
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - JavaScript
---
![[Three Laws of JS]]
## Syntax

- Lines should end in a semi-colon
- is case sensitive
- typed within the `<script>` tag in an html file, or in an external js file

## Data types and variables

- Text based
    - strings/characters
- Dates
- Numbers
    - includes floats and everything!
- Boolean
- is **DYNAMICALLY TYPED**
- new variables are created with the ‘var’ or ‘let’

```JavaScript
var s1 = "test";
console.log(s1);
s1 = 2.2;
console.log(s1);

let s2 = s1;
console.log(s2);
```

- == means same value
- === means same value AND same type

## Logical Expressions

```JavaScript
if(statement){
	spam
}

if(statement1 && statement2){
	spam
}
```

- switch statements require a break between cases

```JavaScript
switch(statement):
	case 1:
			stuff;
			break;
	case 2:
			stuff;
			break;
```

- Also has ternary operators
- And loops!
    - for(initialize variables; check; after loop)

```JavaScript
for(let i=0, x=1; i < 3; i++) {
	console.log("Loop 1: " + i);
}
```

- You can nest for/while loops
- You can also add labels to make break statements more specific

```JavaScript
loop1:
for(let i=0; i < 3; i++) {
	console.log("Loop 1: " + i);
	
	loop2:
	for(let x=0; x < 3; x++) {
		if(x > 1 && i > 1){
			break loop1;
		}
		console.log("Loop 3: " + x);
	}
}
```

- do while loops check the while statement at the END of the loop rather than at the beginning
    - a do while loop will always execute AT LEAST ONCE