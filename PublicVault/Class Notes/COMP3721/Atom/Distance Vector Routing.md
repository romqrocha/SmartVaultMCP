---
aliases:
  - DV Routing
---
- A [[Routing Protocols]]
- A **decentralized** algorithm
- A Distance Vector is a 1D array that contains the [[Least-Cost Path]] to all other nodes
![[DataComm_DVRouting.png]]
- Does not give the **path** to the destinations, just the lowest cost
- Can be changed to a forwarding table
- The algorithm is run by each node independently and asynchronously
	- When a node is booted up, it created a simple distance vector with the information it can obtain from its neighbors
	- The nodes exchange information to update the vector
	- After it creates or updates its vector, it sends a copy to its neighbors
	- When a node receives a Distance Vector from a neighbor, it updates its own using the [[Bellman-Ford Equation]]
	- Eventually stabilizes and all nodes can find the ultimate least-cost between themselves and any other nodes