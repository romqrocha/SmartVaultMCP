# IPv4
- The main [[Network Layer]] protocol
- Responsible for Packetizing, Forwarding, and delivery of a packet at network layer
- Three auxiliary protocols:
	1. [[ARP]]
		- Map network layer address(IP) to link-layer(MAC) address
	2. [[Internet Control Message Protocol v4|ICMPv4]]
	3. [[Internet Group Management Protocol|IGMP]]
		- Helps in multicasting
- *unreliable* [[Datagram]] protocol which provides **best-effort** delivery service
	- May be corrupted, lost, arrive out of order, delayed, etc.
	- This can create congestion
- When reliability is import, must be paired with a *reliable* transport-layer protocol such as [[TCP]]
- Connectionless protocol

## Datagram Format
- Version Number(`VER`)
	- the version number; always 4 for IPv4
	- 4 bits (0100)
- Header Length (`HLEN`)
	- Total length of header in 4-byte words
	- 4 bits
- Total length
	- Total number of bytes in the datagram, including header and payload
	- 16 bits
- Time-To-Live
	- Maximum number of hops allowed
		- Decreases every time the packet is processed
	- 8 bits
- Protocol
	- The packet type carried in the payload
	- Can be associated with Transport **or** network layer
	- 8 bits
- Options/Padding
	- Not required
	- 0-40 bytes
## MTU
- Maximum transfer/Transmission Unit
- Maximum amount of data a [[Data-link Layer]] frame can carry
	- For LAN, usually 1500 bytes
- For IP protocol, it's 65,535 bytes($2^{16}B$)
	- Done to make the IP protocol independent of the physical network
	- If we decide, we don't have to care how large the MTU of the lower layers are
## Fragmentation
- Dividing a [[Datagram]] to allow it to pass through different networks with different [[#MTU]]
- Each fragment has its own header with most the fields repeated, but some may have changed
- Can be fragmented by the source host or any router in the path
	- Reassembly is done **only** by the destination host
- When fragmented, the host sets 3 values:
### Identification Number
- 16 bits
- Same for the original and all fragments
### Flags
- 3 bit
- leftmost bit is not used
- Second bit: Do not fragment($D$)
	- If 1, the Datagram must not be fragmented
	- If it cant fit, discard and send ICMP error
- Third bit: More Fragmentation bit
	- Determines the last fragment(0 for the last)
### Fragmentation Offset
- Specify where the fragment fits within the original
- Units of 8 bytes
- Calculated by $Length Of Fragment/8$
# [[Internet Control Message Protocol v4|ICMPv4]]
![[Internet Control Message Protocol v4|ICMPv4]]
# Transport Layer
- Provides services to [[Application Layer]]
- Receives services from [[Network Layer]]
- is End-To-End **logical** vehicle for transferring data from one point to another in the internet
	- i.e. from Source to destination
- Handles process-to-process communication
- Responsible for the delivery of the message to the appropriate process
## Services
- Process-to-process communication
- Addressing: Port Numbers
- [[Encapsulation]] and [[Decapsulation]]
- Multiplexing and demultiplexing
- Flow Control
- Error Control
### Process-to-Process Communication
- Process is an [[Application Layer]] entity that uses the services of the [[Transport Layer]]
- Most common way to achieve process-to-process communication is [[Client-Server Paradigm]]
### Port Numbers
- Integers between 0 and 65,535 ($2^{16}$)
- For communication, we need to define:
	- Local Host & Process
		- Defined using [[IP Address]]
	- Remote Host & Process
		- Defines using [[#Port Numbers]]
- Port number of the client program is called the *Ephemeral port number*, and $\gt1023(2^{10})$
- Port number of a Server Process is called a well-known port number, and is $\leq 1023(2^{10})$
![[DataComm_PortAddressing.png]]
### Socket Address
- A combination of an [[IP Address]] and a [[#Port Numbers]]
`192.168.0.1:80`
- Client socket address defines client process uniquely
- Server socket address defines server process uniquely
## Flow Control
- Main goal: Avoid overwhelming the receiver
- Can be implemented using two buffers
	- One at sending transport
	- One at receiving transport
## Error Control
- Goal is to make IP reliable, if the application requires it
- Involves ONLY the sending and receiving transport layer
- Receiving transport manages control by informing sending transport about problems
- Achieved with Sequence Numbers and Acknowledgements
### Sequence Number
- Assigned to packets in the header
- Sequence numbers are $\mod2^m$
- Lets the sending transport layer know which packet needs to be resent, if corrupt or lost
- Also allows receiver to check for duplicates or Out-of-order
- Duplicates or corrupted packets can be silently discarded by receiver
- Out-of-order can be discarded or stored until the missing packet arrives
### Acknowledgement
- Receiver sends an acknowledgement(labeled `ACK`) for each, or for a collection, of packets that arrive safe and sound
- Sender can detect lost packets via a timer.
	- If `ACK` has not arrived before timer expires, sender resends.
### Congestion Control
- Goal: Avoid overwhelming the network
- Congestion occurs if the load(number of packets sent to the network) is greater than the capacity of the network
- Congestion happens in any system that involves waiting
- Control refers to mechanisms and techniques that control congestion to keep the load below capacity
## Connectionless Protocols
- No dependency between packets
- Used-by [[IPv4]]
- Used-by [[#UDP]]
- No flow, error, or congestion control
## Connection-Oriented Protocols
- Dependency between packets
- Used-by [[#TCP]]
- Has flow, error, and congestion control

## TCP

## UDP
- Is Unreliable
- Is [[#Connectionless Protocols]]
- is [[Transport Layer Protocol]]
- Simple, efficient, fast
	- Minimum overhead
	- Good for sending small messages
	- Faster than [[#TCP]]
- Packets are called [[User Datagrams]]
- Protocol field in IP packet has value of 17
- No [[Flow Control]]
- No [[Congestion Control]]
- No [[Error Control]]