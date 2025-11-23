>[!danger]- This solution is not good.
> If a process turns off interrupts and doesn't turn them back on again, that could be the end of the system.
- A type of [[Mutual Exclusion]]
- Disable all [[Interrupts]] just after entering a [[Critical Region]], then reenable them as you leave.
- Since the [[Central Processing Unit|CPU]] only switches as a result of the clock or other interrupts, this stops the interrupts from switching to another process.
- Because there are no other processes, we can use and update the shared memory without worrying about other processes manipulating it as well.
- On [[Processor-Level Parallelism|Multiprocessor]], disabling interrupts affects only the CPU that executed the disable instruction.