---
Created: 2024-03-30T14:49
Class: Comp1712 - Biz Analysis & System Design
Reviewed: false
---
# Logical vs Physical DFD

- Logical model is tech agnostic, only there to get a _business view_ of the system.
- Physical model gets into the details and give us a _systems view/technical view_ of the system
    - Includes details such as:
        - Referencing the actual technology
        - The format of the information, and what the data flows contain
        - Where human interaction is required or included
- When converting a DFD to a Physical Data Model:
    1. Add implementation details, such as Input/output forms, or if something is a MYSQL read/write.
    2. Add technologies related to each step, such as front/back end technologies.
    3. Add boundaries around human-machine interactions
        - This tells us there is a boundaries between manual and automated processes, and can help to identify bottlenecks due to human-machine interactions
        - The ultimate point is to track that your system has interactions with the outside world, which you inevitably will need to know.
    4. Update the elements in the date flows
    5. Update the metadata in CASE/documentation software

# Designing Programs

- Program Design Techniques are useful for designing ‘_good programs_’
    - good program design is 2 things fundamentally:
        1. To define the high-level structure; components, their relationships, their exchanges
        2. The logic inside each of the modules/functions
            1. These are designed through Program/Functional specs
    - Helps us understand existing codebase
    - Helps us re-organize/refactor code to help keep it consistent
    - Helps us write original programs or piece together existing software
- What makes a good program?
    - Easy to maintain
    - Modular
    - Flexible
    - “Clean Code” is a good book to learn more
- One Design Technique is called the **Top-down Modular Approach**
    1. Create a high-level diagram that shows
        1. The various components of the program
        2. How the components are/should be organized
        3. How the components are related
    2. Once the overall program is defined at a high level, we go ahead and define the logic of each smaller module
- The structure chart is a way to show how a program **MIGHT** be designed

```Mermaid
graph TD
%%Control Module              Subordinate Modules
  CREATE_STUDENT_LISTING --> GET_STUDENT_GRADE_RECORD --> CREATE_STUDENT_LISTING
  CREATE_STUDENT_LISTING --> CALCULATE_CURRENT_GPA --> CREATE_STUDENT_LISTING
  CREATE_STUDENT_LISTING --> CALCULATE_CUMULATIVE_GPA --> CREATE_STUDENT_LISTING
  CREATE_STUDENT_LISTING --> DISPLAY_GRADE_LISTING --> CREATE_STUDENT_LISTING
```

- At the top is a Control Module
    - Think of this as an entry-point into the logic
    - It controls the flow into the Library Module, and the Subordinate Modules
- Under it are Subordinate Modules, which are the functions that help your Control Module do its specific job
- Library modules are a kind of Subordinate Module that are generic and useful in many circumstances, like the standard libraries you import
- A Data Couple shows the data flowing back and forth between the Control Module and the Subordinate modules
- A Control Couple, also known as Flags, show what sorts of errors/flags/exceptions can be raised so we can handle them successfully.

## Creating a structure chart

- DFDs are a common starting place
    - Each level maps to a level of a structure chart
    - Each process of a DFD maps to a module on the structure chart
    - The challenge is **How should we organize** these modules to show sequence(who calls whom), selection(Conditional execution), and iteration(If there is repetition).
- Guidelines:
    
    - Cohesion:
        - Ideally a module should do one thing and do it well.
        - The more tasks it tries to do, the more complex the logic in it will be.
    - Loosely Coupled:
        - Modules should be independent
        - This prevents changes in one module from rippling through the program
    - Create high fan-in:
        - This means each sub-module should be reused in many places
    - Avoid high fan-out:
        - This means doing the same type of function in many different module, rather than using a single invocation.