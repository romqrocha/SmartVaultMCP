---
Created: 2024-02-15T13:31
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - JavaScript
---
![[/COMP_1537_-_Week_5_-_JavaScript_and_Objects.pptx|COMP_1537_-_Week_5_-_JavaScript_and_Objects.pptx]]

![[/COMP_1537_-_Week_6_-_Intro_to_Node.pptx|COMP_1537_-_Week_6_-_Intro_to_Node.pptx]]

![[/express-routing.zip|express-routing.zip]]

Check out Node package “Express” - makes server side coding super easy, and is used in this course a bunch.

![[Three Laws of JS]]
## Webservers

- SUPER simple
- Basically just responds to requests
    - Do you have this image? Yes/No
    - We get **Status Codes** back
- Looks after all the files that exists
- Runtimes get called when you make request for files with specific extension
    - e.g. spam.php makes the server pass the request to the php runtime
- “Apache is like a server in a restaurant. You want napkins? They get you napkins. You want cutlery? They get you a new fork. You ask for a custom meal? They pass that to the cooks(php) so they can generate new things on the spot.”

# Intro to Node

- A server-side run-time environment
- Single-threaded
- Node is a COMPILED language
    - It takes your JS code, and compiles it on the first run
    - Called “Just-in-time” compilation
    - Stores the machine code in memory when the Node server is running
- uses “Event driven” architecture
    - Fancy way of just saying it responds to events - think how a GUI responds to your clicks
- LOADS of modules
    - see Node Package Manager(NPM) - [https://www.npmjs.com](https://www.npmjs.com)
    - “If you can think of something you want to do with your server, there’s a package for that”
- Non-blocking functions
    - Main execution returns immediately after the call is made.
    - Will get back to this

### Who’s using it?

- LinkedIn
- Netflix
- PayPal
- Trello
- Uber

## Strengths

- Same language as the browser, so less to learn
- High I/O output
    - Text chat, video/audio streaming, frequent transaction processing
- light, compared to Java EE
- LOTS of modules
- Easy to integrate with Front-end frameworks

## Weaknesses

- Single-threaded
- Not as mature as others
- Minimal rules means its easy to write bad code ([http://callbackhell.com/](http://callbackhell.com/))

## “Require” modules

- require(”packageName”); == import statement in Java
- Can go anywhere, like Python
- not QUITE the same as a Java Import statement
    
    - require is a FUNCTION, compared to Javas import STATEMENT
    - require can be stored in an object as a **Function Object**
    - Function Objects can be used as BOTH functions AND objects
    
    ```JavaScript
    const express = require("express");
    const app = express(); //using express as a function
    app.use(express.json()); //using express as an object
    ```
    
    - You can also define a function within another function without invoking it
    - When you declare a function, both inside and outside another function, they aren’t called
        - Just to make it easier to remember that the inner function isn’t being called
    
    ```JavaScript
    // First argument == Root of server
    // 2nd argument is an anonymous function, declared within the argument
    // The 2nd argument is called when the path that is Arg 1 is called
    app.get("/", function (req, res) {
    	// Uncomment the next line to see this work. You'll see it whenever you refresh the page.
    	// console.log("User has selected the root path");
    	// retrieve and send an HTML document from the file system
    	let doc = fs.readFileSync("./app/html/index.html", "utf-8");
    	res.send(doc);
    });
    ```
    
    - A function without a name, usually as a parameter, is called an **anonymous function**
    - When we declare a function within a function, it’s called a **callback** function
    - A callback function commonly have 2 arguments within them
        - req = Request Information
        - res = Response Information
    - req and res get sent as objects
- Header > Accept
    - Lists all the stuff that COULD be inside the req header
- “Web is not just about HTML, or JS, or CSS. Its about client-server programming.”