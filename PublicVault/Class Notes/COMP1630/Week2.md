---
Created: 2024-05-15T18:39
Class: COMP1630 - Relational Databases
Reviewed: false
---
# Data Models (Logical)

- We will get system requirements from the client, if external, or the Project manager/Business Analyst if internal
- We use those requirements to make a model of the database so we can design it before we actually start developing it
- A _Data Model_ shows the relationship between entities in a simplified and generalized form
- The general rule is that you should only save any piece of information once
- We can use the model to check if we’re capturing all the information we want/need
- There are 4 basic building blocks for data models
    - Entities
        - A collection of similar items; the tables in a database
        - Person, Customer, Country, School
        - NOUNS
    - Properties/attributes
        - Qualities of the entity
        - ADJECTIVES
    - Relationships
        - Specifies the association between entities
        - A student _attends_ a specific school
        - VERBS
    - Constraints

## Chens Notation

- Entities are in rectangles
- Attributes are in ovals
    - An attribute has more than 1 oval around it, then it means an entity can have multiple instances of the attribute
    - if the oval is dotted, its a derived attribute
- Primary keys are bolded and underlined
- Relationships are contained with a diamond between 2 entities
- Doesn’t show cardinality

  

## Crow Foot Notion

- Entities are in a rectangle
    - Entity name is the header
- Attributes are written inside the the entity, under the header
- Primary Key is bolded, and written immediately under the name
- Relationships are shown as a line between the entities
    - a line that branches with a W like shape tells you it can contain multiples
- Constraints are shown on the line as either an O or an I
    - O for optional
    - I for required

  

# Primary Keys

- Must be unique
- Must not be empty/null
- Must value should not change
- As a best practice, should be auto-generated
- Can be made of more than 1 attribute
    
    - Called Composite Primary Key (Composite PK)
    
      
    
      
    
- ERDs will naturally evolve over time