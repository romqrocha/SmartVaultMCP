---
Created: 2024-03-07T13:33
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - Database
---
# Relational Model

- The model used in Relational DataBase Management Systems (RDBMS)
- Table Spaces (Aka, DBs) have:
    - Tables with Columns and Rows(A spreadsheet!)
        - Rows(Tuples, records) have:
            - Attributes(Columns)
                - Should be SINGULAR(order_id, item_id, etc)
            - Primary keys(Unique identifiers for a row)
            - Foreign Keys(For identifying rows within another table)
                - must be unique in their own database, but doesnt have to be unique as a Foreign Key
                    - A customer placed two orders, so the customer_id is listed twice
                    - however, the order_id must be unique.
- We use a Query Language to interact with the data in a Relational Database (Structured Query Language; SQL!)
- Relational Model is useful for asking questions about relations between two items
    - How many _customers_ in _Vancouver_ purchased the blender model _xyz_ in the last 6 months **and** whose purchase total was over _$500_?
- This lets us store MASSIVE amounts of information efficiently
- We can also Data Mine the databases to predict trends/behaviors, or find new patterns and trends.

# Databases

- A database is a server
- “Speaks” a query language” - SQL (Structured Query Language)
- Can handle multiple requests, and use authentication

# RDBMS In Web

- 3 tiers
    1. Presentation Tier
        - Web Browser/native application (html5, css3, JavaScript)
    2. Application Tier
        - Web server/service
            - PHP, Apache
    3. Database Tier
        - RDBMS
            - MySQL
- Together, they form a 3 tiered web architecture (AKA, a “full stack”)

# RDBMS Concepts

- Entities
    - Any noun
    - Represents a real-world thing.

# Normalization

- A process designed to
    - Organize structured data
    - Eliminate redundance
    - Eliminate the need to restructure the DB when new data is added
- Five levels; 1 through 6.

## First Normal Form

- No repeating/duplicate fields
- Each cell contains a single value (color: red, green)
- Each record in unique, via the primary key.

## Second Normal Form

- All non-key fields depend on all components of the primary key

## Third Normal Form

- No non-key fields depend on another non-key field.