---
aliases:
  - TCP
---
- Reliable [[Transport Layer Protocol]]
> [!note] Application layer relies on TCP to deliver the entire stream **in order, without error and without loss or duplication**
- Stream-oriented protocol
- Connection-oriented protocol
- Explicitly defined phases:
	1) Connection Establishment
	2) Data Transfer
	3) Connection Teardown
- Uses a [[Logical Connection]]
- Is [[Full Duplex]]
- Buffers are necessary for [[Flow Control]] and [[Error Control]]
- Numbers all data bytes that are transmitted
	- Number is independent in each direction
	- Number is used for flow and error control
- Two fields in segment header:
	- Sequence Number
	- Ack Number
	- Each refers to a byte number rather than a segment number
- Control bits:
	- `URG` 
	- `ACK`
	- `PSH`
	- `RST`
	- `SYN` - Synchronize; Used to initiate the handshake
	- `FIN`
- Mandatory [[Checksum]]

## Flow Control
![[Flow Control#TCP]]
# Connection Establishment
- [[Client]] initializes a connection with a [[Server]] by sending a `SYN`
- Server responds with a `SYN` and `ACK`
	- Tells the Client the window size
- Client responds with its own `ACK` and tells the server its window size
# Connection Termination
- Either the client or server can close the connection
- Usually initiated by the client
- Two ways to terminate:
	- Three way handshake
	- Four way handshake with half-close
![[TCP_Terminate_HalfClose.png]]
# Error Control
![[Error Control#TCP]]
# Congestion Detection
![[Congestion Detection#TCP]]
# Congestion Control
![[Congestion Control#TCP]]