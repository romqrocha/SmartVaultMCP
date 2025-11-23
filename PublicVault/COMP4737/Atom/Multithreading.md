---
aliases:
  - Hyperthreading
  - Multiprocessing
---

- Allows a [[Central Processing Unit|CPU]] to hold state of two different [[Thread|Threads]] at the same time, then switch back and forth on a nanosecond time scale.
	- Can also intelligently switch whenever one process is waiting for an IO Operation to complete.
- Each thread appears to the OS as a separate CPU.
	- This means the CPU may schedule 2 tasks on the same physical CPU rather than actually assigning it to 2 different physical CPUs
- Is not true [[Parallelism]], since only one [[Process]] is running at a time.