---
Created: 2024-03-05T08:34
Class: Comp1800 - Projects
Reviewed: false
---
# Big Ideas

- A database is a software that is made is store a bunch of stuff.
- A server is a computer where the software lives.
- **Relational** databases are stored using tables
    - SQL
- **Non-Relational** uses _key-value_ pairs to store data
    - XMl
    - JSON (Java Script Object Notation)
    - etc
- Firestore is Json-like

# FireStore

- A _collection_ of _documents_
- Documents have _key:value pairs_

## Firestore Read

- .onSnapshot() - continually listens for changes on the path.
- .onGet() - gets the documents contents as they are RIGHT NOW.
    - IS ASYNCHRONOUS
    - Use .then() to do something SYNCHRONOUSLY after with a callback function
- Most database functions are Asynchronous
    - if we need data from functionA in functionB, we can feed functionB as a callback
        - functionA().then(functionB(data));
- .where() can be used to sort array data returned
    
    ```Java
    doc.where("capital", ==, true)
    	.get().then(...);
    ```
    

## Write

- .set()
- .update()
- .add() will generate a new document with auto-generated data.

## Callback Notation

- Sometimes uses ``` => ``` to annotation that a variable is being fed into a callback function

```Java
.onSnapshot(doc => {
	console.log(doc);
});
```