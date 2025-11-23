---
Created: 2024-03-28T13:45
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - WebDev
---
# Persistence

- Save data so we can access it at a later time, even after the server or web application is shut down.
- Options:
    1. Cloud computing services
    2. Relational Database Management Systems (RDBMS)
    3. noSQL storage system, such as Mongo, that uses Json for storing textual data.
    4. Session Management Systems
- Client side we have:
    1. Cookies
        1. Text string; 1024 characters
    2. Local storage
        1. Stays until its full or user deletes it
        2. You can see it in the console by typing “localstorage”
    3. Session Storage
        1. If you close the tab, its gone
    4. IndexedDB
        1. [https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API)

  

## Local Storage

- Good:
    - About 5mb of data that lets us store key:value pairs.
    - Exists as long as it doesnt overfill, or the user doesnt delete it
- Bad:
    - Device specific- many users may not see the same data

## Session Storage

- Good:
    - Fast, ~5MB, exists as long as the tab is open - ideal for transactional and private data.
- Bad:
    - Lost when the user closes the tab.

  

## Sessions

- A way of keeping track of users, restricting access vis authentication, providing timeouts, keeping track of analytical data.
- Think of it as a wristband for a concert or a festival.
- A few ways this is done:
    - Storing session data on the server and passing it to the user/browser
    - Cookies on the users browser
- HTTP is stateless, so it cant inherently keep information.
    - This means we need to keep track of the authentication somehow

# Sessions in Express

- use express-session
- Stored in RAM by default, this is bad because it will freeze the OS.
- express-session has modules that plug into dozens of datastores, such as Firebase, MYSQL, MongoDB, etc.
- So which server do we use?
    - MySQL is already installed and is efficient
    - MongoDB is installed and good for JD
    - redis([https://redis.io/](https://redis.io/)) is an in-memory key-value datastore
        - This means its stored in RAM