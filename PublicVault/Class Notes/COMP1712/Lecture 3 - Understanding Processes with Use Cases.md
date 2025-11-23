---
Created: 2024-01-29T10:44
Class: Comp1712 - Biz Analysis & System Design
Reviewed: false
---
Requirements

Use Cases

User Driven Programming

Use Case Definition Document

Summary

Identifying Major Use Cases

Confirm the Use Case

Revise Functional Requirements

## Requirements

- ==Definition:==
    - ==What should a system do something, or how should it work==

- Changes based on perspective
    - Business requirement
    - User requirement
        - The things the user needs to accomplish with the new system
    - System requirement
- Everyone looks at a system from **THEIR** point of view
- 2 broad categories
    - Functional
    - Nonfunction

# Use Cases

- A way to express USER REQUIREMENTS
- “A case of using the system”
- Learning hub examples:
    - To submit assignment, you **go to learning hub**
- Represent the ways the system RESPONDS to a user
    - Users perform ACTIVITIES
    - System generates RESPONSES
- Gives us an **external/functional** view of a business process
    - Help us understand internal Functional Requirements better, since we need to design around the responses
    - A user requirement IS a functional requirement

### User Driven Programming

- Everything can be thought of as a response to a triggering event
    - Think of a KEYBOARD - every input triggers the system to output a character on the screen

## Use Case Definition Document

- Actors:
    - The actor of a use case can be a person, or another system (APIs, or sending a photo between devices)
- Trigger:
    - Ask “When/where would this task be activated”
- Trigger Type:
    - 2 types of events
        - Temporal(Based on time)
            - Run X function every Y hours
        - External
            - When someone interacts with the system
- Preconditions:
    - Define the state the system must be in before the use case activates
- Normal Course:
    - Major steps performed when the Use Case happens
    - Sometimes called the **Happy Path**
    - Written from an external perspective, very high level - **Birds Eye**
    - Might include **Branching Logical Conditions**
        - If item is out of stock
            - A) User can do A
            - B) User can do B
- Postconditions:
    - Outcomes/Final Product of the use case
        - Output
    - May define the preconditions for other use cases

### Summary

- Use Cases only show the USERS point of view
    - The Analyst must convert that to the **developers** point of view by creating **functional requirements**
- When thinking about Use Cases
    - Be abstract
    - language agnostic
    - Open to refinement and restructuring

## Identifying Major Use Cases

- Goal: **Identify Major Use Cases with basic information**
    - No need to describe it entirely, just to figure out basic input/output, and actors of each step
- This helps minimize overlap between use cases
- Look for the things that cause your system to be activated
    - Called the **Major Events** of the system
- Try to develop **Major Responses** to those events
- Then develop an **Event-Response List** to track the events and their responses
    - A simple table will do
- Not all Major Events will become use cases - several small ones may be grouped together
- Once all Major Events are gathered and written as basic Use Cases, we can identify Priority of each event
- Interview question to find use case information:
    - “What tasks do you need to do before you can start?” - Prerequisites
    - “How do you know when you are finished?” - Postconditions
    - Try to have the user picture themselves writing a recipe for a cookbook

## Confirm the Use Case

- Users should be the ones to confirm the use case is correct
    - Use a paper prototype or do a mock verbal walkthrough of the system

  

## Revise Functional Requirements

- Modify the functional requirements
    - The updates should provide Technical Requirements for programmers