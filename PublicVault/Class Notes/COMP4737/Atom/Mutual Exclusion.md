>[!note] Some way of making sure that if one process is using a shared variable or file, the other processes will be excluded from doing the same thing.

![[Busy Waiting]]
![[Disabling Interrupts]]
![[Lock Variable|Lock]]
![[Strict Alternation]]
![[Peterson's Solution]]
![[Test and Set Lock Instruction]]
![[Sleep and Wakeup]]
![[Semaphore]]
![[Monitor]]
# Message Passing
>[!note] Commonly used in [[Parallel Programming]]
- [[Semaphore]] are too low-level and [[Monitor]] are not usable, except in a few programming languages
- [[Primitive Type]] do not allow information exchange between machines
- A [[Consumer]] sends messages to the [[Producer]], asking for data.
- If the consumer works faster, all the messages will be empty, waiting for the producer to fill them and send them back.
- If the producer works faster, then the producer is blocked and waits for an empty message to come back.
- Similar to how [[Packets]] are passed.
# Barriers
>[!note] a [[Synchronization Mechanism]] for groups of [[Process|Processes]] used in applications with many phases
>No process may proceed into the next phase until all processes are ready to proceed into the next phase

![[Synchronization_Barriers.png]] 