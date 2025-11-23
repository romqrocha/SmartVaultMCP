---
aliases:
  - LSDB
---
- The collection of states for all links
- Only one for the whole internet
- Each node has a duplicate of it
- Represented as a 2d array(matrix)
- Created by receiving [[Link-State Packet]] 
	- If the received packet is newer, discard the old one and send a copy out to each interface except the one it came from