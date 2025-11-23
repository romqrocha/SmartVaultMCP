---
Created: 2024-02-15T14:59
Class: Comp1537 - WebDev
Materials:
  - "[[/javascript-DOM-and-Events.zip|javascript-DOM-and-Events.zip]]"
  - "[[/COMP_1537_-_Week_8_-_DOM_Creating_and_Events.pptx|COMP_1537_-_Week_8_-_DOM_Creating_and_Events.pptx]]"
Reviewed: false
tags:
  - HTML
  - CSS
  - JavaScript
  - WebDev
---
# DOM

- DOM = Document Object Model
- Has its own class hierarchy - technically interfaces

## Creating Elements & Attributes

- Put your script at the end of your HTML file
    - document keyword references the document the script is within
        - This allows you to replace what’s in the head and body, but you can’t remove either
        - This means we have a **self-changing website**
    - document.createElement lets you make a new element(div/p/etc)
    - document.setAttribute lets you set the attributes of a element you pass in
    - document.innerHTML lets you put mixed content inside of any element
        
        ```JavaScript
        doc.innerHTML = "A <b class='bigger' style='font-sze:22pt;'>new</b> bit of content";
        ```
        
    - We can put a script element, or style elements, inside a page using this

### Events

- see DOM-traversing.html for how to programmatically traverse a page for elements via recursion.
- see DOM-basic-event-handlers.html
- Query selector:

```JavaScript
// Replace spam with anything you want to query; such as div, p, a, etc.
document.body.querySelector("spam").childNodes;
```

- Events happen when we do stuff, such as
    
    - Move the mouse into an area
    - click a specific thing
    - really, anything you want.
    
    ```JavaScript
    // Note you can do element chaining!
    document.getElementByID("spam").addEventListener("click, callback(event) {
    	//add stuff for callback method
    }, false);
    ```
    
    - Javascript has _Hoisting_, so we can use a function name, like in a callback, then define it later.
    
    ```JavaScript
    document.getElementByID("spam)
    	.addEventListener("click", clickMe);
    	// Notice clickMe is being passed as a function,
    	// rather than being called with ()!
    
    //Hoisted function
    function clickMe(event) {
    	//Do stuff on click in here!
    }
    ```
    
- event argument information comes from the system itself when an event happens, and is passed to any listener functions.