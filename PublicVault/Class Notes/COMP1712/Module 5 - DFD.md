---
Created: 2024-02-05T10:30
Class: Comp1712 - Biz Analysis & System Design
Reviewed: false
---
# Data Flow Diagram

- The ultimate goal of designing process models is to decompose a process so that each child process performs one AND ONLY ONE essential task.
- A set of diagrams that show how data flows within a system
- The focus is on **data flow**
- Different shapes used to represent different information
    - A cube might be an Actor, a rounded cube might be a process, etc.
- Represented
    - External Actors
    - Internal Processes
    - Data Saved
    - Inputs/Outputs

## Processes

- an activity or function
    - Can be manual or automatic
- Each process does **ONE** thing
- Each process needs **at least** one input and one output

## Visualizing

- Gane and Sarson symbol
    - A process
    - Has a number/ID
    - Has a description
        - Needs a verb
        - If it has a “And”, it should be 2 functions
- DeMarco and Yourdon symbols
- All connected by arrows
    - All arrows have a title showing WHAT is moving along that dataflow
    - Should always be a proper noun!

### Data Storage

- Think of this as a VARIABLE in programming
- Data shouldn’t be stored unless its used by 2 or more processes
- Every data store needs AT LEAST 1 data INPUT and 1 data OUTPUT

### External Entity

- A Person, organization, or System that is external to the system, but interacts with it
- Typically a primary actor when making a Use Case

## Making sets of DFDs

- Most systems are too complex for a single diagram, so we make a tree
- We start with a “Context Diagram”, which is an overview of the whole system
    - Will be highly abstracted, and high level.
    - Basically just shows “The System”, and all I/Os for the system.
    - Should only have 1 process shown, which will be labeled as Process 0, and named after the system as a whole
    - First diagram is called “Level 0 Diagram” and starts to go into detail about the system.
- Each process from the Context Diagram we make a new DFD
- Repeat this process for each DFD until you have no more systems.
- Each new level will be labeled as “Level X Diagram”
    - Each process within that level is labeled as “Process X Level X Diagram”
    - Sub-processes are labeled as “Process X.Y”
- All context diagrams are _balanced_
    - Balanced means all information is accurately represented and named the same between levels of diagrams

## Creating DFDs

- Start with all the information in the use cases and requirements definitions
- Not all processes in the requirements definition are written as use cases, so the DFD combines all this information in a single format.
- Useful method:
    - Build the Content diagram
    - Create a DFD Fragment for each use case
    - Organize all fragments into a Level 0 diagram
    - Develop the Level 1 DFDs based on the Level 0
    - Validate all the DFDs
    - Repeat with each level.
- Try to reduce the number of times that data flow lines cross
    - If they must, use a line jump to make sure its clear

## Validating DFDs