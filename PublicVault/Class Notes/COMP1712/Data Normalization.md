---
Created: 2024-02-19T19:14
Class: Comp1712 - Biz Analysis & System Design
Reviewed: false
---
- Normalization is the attempt to confirm you’ve created a good model
- Ask questions such as “Have we detected the right entities?”
- When given a table of data, look for repeats
    - Repetitions are not good in a database environment
    - If an entity changes its information, or needs to be removed, it needs to be updated everywhere it is, which increases the odds for mismatches
        - A mismatch of data is called an “anomaly”
- Group the data so every row consists of a single item

# Forms

## First Normal Form (1NF)

- A table is in 1 Normal Form(1NF) if it does not contain attributes that have multiple values for a single instance of the entity
    - e.g. - “Employee reviews” Would hold multiple “reviews” in the same cell.
- Just because a table is in 1NF, it doesn’t mean its good.
- Repeating cells also can include two cells that are naturally related
- Project # and Project Name are linked, one relies on the other to be defined
- this is called **Functional Dependence**
    - If you know Project #, you know Project Name
    - One of these pieces of data is the “Determinant”, and the other is the “Dependent”. The Dependent relies on the Determinant to get its value; therefore, we can remove the Dependent from our table.
    - We can have multiple Dependent on a single Determinant; e.g. an Employee # can tell you Employee Name, Job Title, and Wage
- A **Partial Dependency** is when one attribute is dependent on some, but not all, of the identifiers of a entity
    - When you see this, it tells you the dependent attributes belong in another entity
    - We can represent this in excel by creating new tables for each _entity_ we want to represent. Each _column_ should be an attribute, and each _row_ should be a unique instance of that entity
- Our goal is to have entities that contain attributes that are **dependent on the whole identifier**, not just part of it
    - Because we want the attributes to be about the entity, not about **parts** of the entity

## Second Normal Form (2NF)

- Requires each entity is in 1NF, and has only attributes that depend on the whole identifier, and not a part of it.
- When an attribute _depends on a non-identifier attribute_ it is called a _Transitive Dependency_
    - This suggests the dependent attributes belong in another entity

## Third Normal Form (3NF)

- Requires each entity is in 2NF and has no transitive attributes
- Derived Attributes can be calculated from other attributes, so they don’t need to be stored in the data model