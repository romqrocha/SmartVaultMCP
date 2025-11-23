- Receives incoming [[Frame]] and forwards them, based on [[MAC address]]
- Hosts don't know there are switches between them and their destination
- Don't need to be configured
- Learns which hosts can be reached through which interfaces through [[ARP]] and saves that information into a [[Switching Table]]
# Advantages
- Eliminates collisions
	- Buffers frames
	- Never transmits more than 1 frame on a segment at any one time
- Links with different speeds and running over different transmission mediums are combined
- Ease of network management
	- Detecting disconnecting and malfunctioning adapters
	- Offers stats on bandwidth use, traffic types, etc
# Disadvantages
- Lack of traffic isolation
- Low security and privacy