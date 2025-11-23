> [!note] Situations where two or more [[Process|Processes]] are reading or writing some shared data, and the final result depends on who runs precise when.

- [[Part_6_7_IPC_1.pdf#page=4&selection=14,0,22,7|Race Condition Example]]
## Avoiding Race Conditions
1. No two [[Process|Processes]] may be simultaneously inside their [[Critical Region]]s. 
2. No assumptions may be made about speeds or the number of [[Central Processing Unit|CPU]]s.
3. No process running outside its critical region may block other processes.
4. No process should have to wait forever to enter its critical region.