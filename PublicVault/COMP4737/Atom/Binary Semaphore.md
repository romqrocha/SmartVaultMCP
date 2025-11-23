- A type of [[Semaphore]]
- AKA Mutex
>[!note]- A Mutex is a shared variable that can be in one of two states; Locked or Unlocked.
>Can easily be implemented using 0 and 1, or a [[Boolean]] value
- Used for [[Mutual Exclusion]]
- Can easy be implemented in [[User Mode]] provided that a [[Test and Set Lock Instruction|TSL]] instruction is available.