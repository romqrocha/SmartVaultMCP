- Example: [[The Internet]]
- At this level: 
	- Packets are called [[Datagram]]
	- Switches are called [[Router]]
- Datagram switching is normally done at the [[Network Layer]]
# Error Control
- Checksum field in the header of the datagram to control any corruption in the header
	- Inefficient to check the contents because the packet may be fragmented at the router
# Performance metrics
## [[Delay]]/Latency
- How long it takes for an entire message to complete arrive at the destination from the time the first bit is sent from the source
![[DatagramNetwork_Delay.png]]
### Transmission Delay
-  Time taken to push all bits of a message/packet onto a link
- Depends on the **size** of the message, and the [[Bandwidth]]/Transmission rate of the channel
$Delay_{tr}= Packet Length / Transmission Rate$
### Propagation Delay
- AKA Propagation Time
- Time required for a bit to travel from source to destination
- depends on the medium
$Delay_{pg} = Distance / Propagation Speed$ 
### Processing Delay
- AKA Processing Time
- The time required to process a packet in a router or destination host
	- Remove the header
	- Perform error detection
	- Deliver the packet to the output port/upper layer
- Can be different for each packet, but normally calculated as an average
- $Delay_{pr}$ is going to be given if its required.
### Queueing/Waiting delay
- Time needed for each intermediate or end device to hold the message before processing
- Changes with the load incurred on the network -> Its not a fixed value
- A router has an input queue connected to each of its input ports
- A router has an output queue connected to each of its output ports
### Total Delay
- Assuming equal delays for sender/routers/receivers
- $n$ is the number of routers, so $n+1$ lines
	- $n+1$ transmission delays related to $n$ routers and the source
	- $n+1$ propagation delays related to $n+1$ links
	- $n+1$ processing delays related to $n$ routers and the destination
	- $n$ queueing delays related to $n$ routers
$TotalDelay = (n+1)(Delay_{tr}+Delay_{pg}+Delay_{pr}) + (n)(Delay_{qu})$
## [[Throughput]]
- How fast we can actually send data through a network
- Different from bandwidth in bits per second
	- Bandwidth is the **potential** measurement of a link
	- Maximum throughput = Digital Bandwidth Capacity
- Determined by the bottleneck link
- For a path with $n$ links:
	- $Throughput=min\{TR_1, TR_2, TR_3, ..., TR_n\}$
## [[Packet Loss]]
- The number of packets lost can affect performance
- If the buffer is full, the next packet is dropped
- This means packets are resent, which means we're using twice the bandwidth for 1 packet
## [[Jitter]]
- Variations in delay