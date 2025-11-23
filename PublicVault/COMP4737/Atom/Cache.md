---
aliases:
  - Caching
---
- Mostly controlled by the Hardware
- Divides [[Main Memory]] into Cache Lines, typically 64 bits
	- Address 0->63 in Line 0, 64->127 in Line 1, etc.
- When a program needs a memory word, the Cache Hardware checks to see if the line requested is currently stored
	- If it is, its called a Cache Hit and the information is sent from cache
	- Otherwise, called a Cache Miss, go to the next level of Memory
- Several fundamental questions in any Caching system
	1. When to put a new item into the Cache
	2. Which line to put the item in
	3. Which item to remove when a slot of needed.
	4. Where to put the removed item in memory.