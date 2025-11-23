---
aliases:
  - Critical Section
---
- Its important to make sure there is [[Mutual Exclusion]] for shared resources
>[!note] The part of a program where shared memory is accessed
# Rule 1
>[!danger] No two processes may simultaneously inside their Critical Regions
# Rule 2
>[!danger] No assumptions should be made about the speeds or number of [[Central Processing Unit|CPUs]]
# Rule 3
>[!danger] No process running outside its critical region may block other processes
# Rule 4
>[!danger] No process should have to wait forever to enter its critical region
