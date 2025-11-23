---
Created: 2024-02-22T14:26
Class: Comp1537 - WebDev
Materials:
  - "[[/node-ajax.zip|node-ajax.zip]]"
  - "[[/COMP_1537_-_Week_9_-_AJAX.pptx|COMP_1537_-_Week_9_-_AJAX.pptx]]"
Reviewed: false
tags:
  - JavaScript
  - WebDev
---
- When we go to a page, it has to load EVERYTHING
- This means if the user changes the page, it loads the entire new page, then has to reload the last page when they go back
- We can reduce this with AJAX calls, to change just a small piece of the current page
- Asynchronous Javascript And XML
    - Asynchronous: Code makes a call and returns immediately rather than waiting for a response
    - JS- language for client to interact with a server
    - XML - a syntax for structured data(e.g. HTML)
        - Note: Doesn’t have to be XML, just has to be structured(E.g. JSON)
- Look at /public/js/client.js
- res.setHeader() is used to tell the browser what we’re sending it
- We talk to the server from the client.js code with a XMLHttpRequest() object
    - We can define a callback function before we connect using onload
    - then we open and send the request
    - Once it finishes loading, the callback is run
- To parse JSON, make sure you dont forget line 53 in the client.js