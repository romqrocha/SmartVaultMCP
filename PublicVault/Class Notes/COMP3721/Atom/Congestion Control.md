# TCP

^3b7593

> [!note] Avoid overwhelming the network
- Maintains a state variable for each connection called the [[Congestion Window]]
	- This imposes a limit on the rate a sender can push traffic onto the network
- Maximum unacknowledged(in-flight) data bytes <= `cwnd`
- Three main components:
	- [[#Slow Start]]
	- [[#Congestion Avoidance]]
	- [[#Fast Recovery]]
## Slow Start
- Size of congestion window begin at 1 [[Maximum Segment Size|MSS]] and is doubled per [[Round Trip Time|RTT]]
	- Exponential increase continues until a threshold is reached (`ssthresh`) or is restarted if congestion is detected
	![[DataComm_SlowStart.png]]
## Congestion Avoidance
- A more conservative approach
- Size of window increases each RTT linearly until congestion is detected
## Fast Recovery
- New versions of TCP use it
- Starts when 3 duplicate `ACK` arrive
	- This means it starts with light congestion