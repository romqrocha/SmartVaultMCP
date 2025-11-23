---
Created: 2024-02-15T14:24
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - JavaScript
---
# THE THREE LAWS OF JS

1. Objects are “Associative Arrays”
    - Information
        
        - Like a dictionary in Python
            - Key : Value pairs
        - Properties are added as you go.
            
            ```JavaScript
            var object = new Object();
            obj.firstName = "corey";
            obj.lastName = "Buchan";
            console.log(obj.firstName); //Dot Notation
            console.log(obj["firstName"]); //Array Notation
            ```
            
        - You can also make new objects with {}
            
            ```JavaScript
            var object = {};
            obj.firstName = "corey";
            obj.lastName = "Buchan";
            console.log(obj.firstName); //Dot Notation
            console.log(obj["firstName"]); //Array Notation
            ```
            
        - You can also create objects with **JSON Notation**
            
            ```JavaScript
            let person = {firstName: "Corey", lastName: "Buchan", email: "cbuchan11@my.bcit.ca"}
            ```
            
        
          
        
2. JavaScript functions are **objects**
3. You can pass them in as arguments
    1. This means they are “First Class Citizens”
    2. Because they are called at a later time, they are known as “callbacks”