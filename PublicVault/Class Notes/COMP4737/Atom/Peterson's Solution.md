>[!quote] Peterson's Solution defines the procedures for entering and leaving the [[Critical Region]]
- A type of [[Mutual Exclusion]]
- Before entering the [[Critical Region]], each process calls `EnterRegion` using its own process number, 0 or 1, as a parameter.
	- This call will cause the call to wait, if need be, until it is safe to enter.
- After finishing in the Critical Region, the process calls `LeaveRegion` to indicate that it is done, which allows other blocked processes to enter if needed.