> [!note] [[Encapsulation|Encapsulating]] the payload(data received from the upper layer) in a [[Network Layer]] packet at the Source, and [[Decapsulation|Decapsulating]] the payload at the destination
> E.g. To carry a payload from the source to the destination without changing or using it.
- The Source Host 
	- receives a payload from an upper layer protocol
	- Adds a header that includes source and destination IP
	- Delivers the packet the the [[Data-link Layer]]
	- May break the packet up with its too large.
- Router on the path
	- Not allowed to change the source or destination [[IP Address]]
- Destination Host
	- Receives the packet from its Data-link Layer
	- Decapsulates the packet
	- Delivers the payload to the corresponding upper-layer protocol