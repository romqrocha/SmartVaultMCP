---
Created: 2024-07-17T18:39
Class: COMP1630 - Relational Databases
Reviewed: false
---
# Triggers

- A special stored procedure that runs when a specific event runs
    - Events can be one or many of the following:
        - Insert
        - Delete
        - Update
        - Drop Table
- During execution, a trigger creates two virtual tables to hold data being affected by the trigger, INSERTED and DELETED
- Can be used to
    - update or insert records,
    - call stored procedures,
    - create audit logs,
    - enforce business/security constraints,
    - replicate data for backup purposes
- Three types of triggers
    - DML Trigger
    - DDL Trigger
    - Logon Trigger

## DML

- Runs when a user tried to modify data through Data Manipulation Language(DML) statements
    - Insert
    - Update
    - Delete

## DDL

  

  

## Summary

|Operation|deleted Table|inserted Table|
|---|---|---|
|INSERT|(not used)|Contains the rows being inserted|
|DELETE|Contains the rows being deleted|(not used)|
|UPDATE|Contains the rows as they were before the UPDATE statement|Contains the rows as they were after the UPDATE statement|

  

# Deadlock

- Occurs when tow or more processes have a resource locked, and wants to lock a resource the other is using