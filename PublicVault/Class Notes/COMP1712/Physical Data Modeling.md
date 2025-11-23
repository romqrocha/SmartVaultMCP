---
Created: 2024-04-08T10:48
Class: Comp1712 - Biz Analysis & System Design
Reviewed: false
---
# Data storage

- two types:
    
    ## Files
    
    - Usually in CSV or Tab-delimited
    - Usually organized as a linked list
    - Types:
        - Master: Store core information
        - Lookup: Used for validation
        - Transaction: Holds transactions as they happen
        - Audit: Keep before/after ‘screenshots’ of data
        - History: Holds past transaction
    
    ## Database
    
    - First question we ask is “How type of data does it store?”
    - Second question is “how is it stored?”
    - Different types of structures for storing data
    - Types:
        - Relational
            - Most popular for application development
            - Collection of table
                - each table has a **primary key**
                - Tables are related through **foreign keys**
                - DBMS guarantees **referential integrity**
                - SQL is used to do CRUD operations
                - Each column has a set data type/format with limits that cannot be escaped.
        - Multidimensional
            - “Cubes” of various dimensions
            - Used in data warehousing for business intelligence systems
            - a series of queries(3 makes a cube), organized as a cube, to allow us to quickly reference and query large amounts of data
        - NoSQL
            
        - Object
- Multiple storage formats might be used in a single format
- Selecting a storage format depends on:
    - Data types
        - Simple: Text, dates, number, etc.
        - Complex: video, images, audio
        - Aggregated
        - Big data: Huge _volume_, rapid _velocity_, great _variety_
    - Type of application system:
        - Transaction processing
        - Business Intelligence (BI)
- Entities → Table
    - Attributes become columns
    - Instances become rows
    - Every time there is a relationship on an ERD, there must be one AND ONLY ONE foreign key, for each line.
        - Nulls should be minimized, if possible.
        - with optional relationships, the FK can be null **THIS IS OKAY**
        - 1:1
            
        - 1:m
            - Foreign key for the 1 side goes inside the many side
        - n:m
            - dont - resolve it with a bridge entity and make it into 1-m [bridge] m-1
                - bridge entity has a foreign key to each entity its attached to
                - primary key is the combination of both foreign keys
        - o:1
            - Foreign key goes on the required side of the relationship so we don’t have null data in the optional side

## Optimizing

1. not just about space; space is cheap
2. speed of access is much more important

- these two goals often conflict
- when we need to access data from multiple tables, we should join the tables together first
- this is usually slow, so we can use:
    - denormalizing
        - Should be used sparingly
        - Ideal when information is queried frequently but updated rarely
        - This can reduce joins, therefore increasing performance in:
            - lookups
            - 1:1 relationships
            - 1:n relationships
            - Star Schema Design
    - clustering
    - indexing
    - estimating the size