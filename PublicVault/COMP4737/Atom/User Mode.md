---
aliases:
  - User Space
---

- Only a subset of the Machine Instructions are available
- Instructions that affect control of the machine **or** do Input/Output are forbidden to user-mode programs
	- If a User Mode program wants to use services of the Operating System, it must make a [[System Call]]