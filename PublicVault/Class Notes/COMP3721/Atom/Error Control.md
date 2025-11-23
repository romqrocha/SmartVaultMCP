# Data Link
- A [[Cyclical Redundancy Checks|CRC]] is added to the frame header by the sender and checked by the receiver
- If corruption if found, either:
	1. Corrupted frames are discard, then uncorrupted ones are delivered to the network layer
		- Mostly used in wired LANs and Ethernet
	2. Corrupted frames are discarded, and an acknowledgement is sent to the sender for the **uncorrupted** frames
		- No acknowledgement could mean cache overflow or error, so the sender can resend.
## Protocols
- Two common protocols:
	1. Simple
	2. Stop-and-wait
### Finite state machines
- **Rounded-corner rectangle** or **circles**  show states
- **colored text** shows events
- **black text** shows actions
### Simple Protocol
- No flow and error control
- Assumption is that the receiver can never be overwhelmed with incoming frames
![[DataComm_SimpleProtocol_FSM.png]]
### Stop-and-wait protocol
- Connection based protocol
- Both flow and error control provided
- Sender sends one frame and waits for acknowledgement before sending the next
- A timer is used by sender
	- If timer expires, frame is resent
- If [[Class Notes/COMP3721/Lecture/Lecture 13#Cyclical Redundancy checks (CRC)|CRC]] is correct, receiver will send an acknowledgement
![[DataComm_StopAndWait_FSM.png]]
- Duplicates and orders can be handled by adding a sequence number and acknowledgement number to frames
- Sequence numbers start with 0, acknowledgement starts with 1
	- Sequence: 0, 1, 0, 1, 0, 1
	- Acknowledgement: 1, 0, 1, 0, 1, 0
# TCP
- 4 mechanisms
	1. [[#Acknowledgements]]
	2. [[#Sequence Numbers]]
	3. [[#Retransmission]]
	4. [[Checksum#TCP]]
## Acknowledgement
- Often abbreviated to `ACK`
- TCP only ACK up to the first missing byte in the stream
- Always 1 bigger than the last byte it received
	- "I'm *expecting* 701 next"
![[DataComm_Ack-Timeout.png]]
## Sequence Number
- Indicates the number assigned to the first data byte in that [[Segment]]
- The number, is each direction:
	- ISN: Initial Sequence Number; The number of the first segment
	- Every following segment has the sequence number of the previous segment, plus the number of bytes carried by the previous segment
- Some segments, such as control information, need a sequence number to allow for [[#Acknowledgement]] from the receiver
	- Connection Establishment
	- Connection Termination
	- Connection Abortion
	- Each consumes one sequence number as though it carries one byte, even though it has no actual data
- Allows for detection of:
	- lost segment
		- Gaps in sequence number of received segment
	- duplicate segment
		- Received segments with duplicate sequence number
	- out-of-order segment
		- Receiver flags the out-of-order segments and stores them until the missing segments arrive
## Retransmission
> [!note] The heart of TCP error control
### After Timeout
- Maintains one timeout for each connection
- When time-out occurs:
	- Segment that caused timeout is resent
	- Timer is restarted
- Value is dynamic; updated based on [[Round Trip Time#TCP|RTT]]
### 3 Duplicate ACK
- AKA Fast Retransmission
- If 3 duplicate acknowledgements are received, it sends the segment the ACK expects without waiting for the timeout
- 3+ duplicate ACK is a strong indication a segment has been lot
## Checksum
![[Checksum#TCP]]