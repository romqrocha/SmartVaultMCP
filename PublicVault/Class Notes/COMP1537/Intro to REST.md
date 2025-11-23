---
Created: 2024-04-04T13:32
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - WebDev
---
# What is REST?

- REpresentational State Transfer
- Another architecture strategy for developing web apps.
- Goals of REST:
    1. Make it scalable
        1. Performance should be consistently responsive
    2. Improve web service interface access, decrease development time/costs
    3. Client-server, stateless
        1. the server stores no data between requests, and the client stores session data
    4. Make known by the server what info to submit and where
    5. offer several formats for data results
        1. json, html, xml
    6. Code-on-demand
        1. extend the functionality of the client
- What’s the strategy used?
    - Expose resources via path structure
    - use HTTP methods correctly
        - get doesn’t alter - considered idempotent (we should get the same results every time)
        - post affects changes
    - use verbs for affecting change
        - add, delete, etc.
    - use nouns for the things that are to be listed/viewed/accessed/changed
    - use HTML and other web media types
    - use a layered system

# Technical Considerations

- Web, Mobile, or both?
    - Web only:
        - One “app” built, accessible by all.
        - disadvantages:
            - Certain things we cant do, some features are inaccessible without explicit user permission
    - Mobile:
        - create specialized UI and get specialized device features
        - disadvantages
            - Larger amounts of time/money testing/developing/releasing apps on multiple platforms. May not be consistent across platforms.
    - Both:
        - get both advantages: cover all bases, much larger audience
        - also both disadvantages: even **more** challenges with testing/deploying/consistency
- Stacks (LAMP/WAMP/MAMP/XAMP)
    - Good: Cheap hosting anywhere, very low resource requirements, common
    - Bad: Hard to do complex things
- Java Enterprise Edition(EE)
    - Java on server, application on client
    - good: Full support, many APIs
    - Bad: heavy memory/bandwidth/resource requirements and use, hosting is expensive, hard to find hosting specific to java EE
- Node:
    - JS on server side
    - good: Supports rapid development, many libraries available, fast and efficient for IO and streaming. It compiles the source code down to machine code when its first run, so it gets faster after the first time you run it.
    - ad: not as mature as .NET or Java EE; single-threaded
- Shared hosting:
    - cheapest
    - good: Very cheap/free
    - bad: slow, cant customize the server, very basic servers
- Virtual Private Server (VPS):
    - Virtual OS so you can configure whatever stack you want
    - Good: Much more control, can be faster
    - Bad: your app may suffer if other are using more time on the network; more expensive.