# Normalization

Normalization is when you break tables up into more, smaller, tables for efficiency.

1. Should be human readable
2. Each table represents a single noun
3. Each row/column intersection contains only one value
    1. this means we don’t need to update it in more than one place
4. All non-prime columns are dependent on the primary key

## Forms

1. First Normal Form(1NF)
    
    1. A single column cannot hold multiple values
    2. Data in a column are all of the same time
    3. Each row is identified with a Primary Key  
          
        
    
    ![[DB_FirstNormalForm.png|DB_FirstNormalForm.png]]
    
2. Second Normal Form(2NF)
    
    1. The table is in 1NF
    2. It has no partial dependencies; no non-prime attribute is dependent on only one attribute of a primary key
        1. This means if you only have 1 primary key, you’re automatically in 2NF
    
    ![[DB_SecondNormalForm.png|DB_SecondNormalForm.png]]
    
3. Third Normal Form(3NF)
    
    1. Table is in 2NF
    2. has no **transitive** dependencies; a non-prime attribute that is dependent on another non-prime attribute
    
    ![[DB_ThirdNormalForm.png|DB_ThirdNormalForm.png]]
    
    ## Data types
    - char takes up the amount of memory required to hold the number of characters given, regardless of the amount of characters inputted
    - varchar expands as required, making it more memory efficient
    
    ## SQL Query
    ![[DB_SQLQuery.png|DB_SQLQuery.png]]
    
    ### With filter condition:
    
    ![[DB_FilterQuery.png|DB_FilterQuery.png]]