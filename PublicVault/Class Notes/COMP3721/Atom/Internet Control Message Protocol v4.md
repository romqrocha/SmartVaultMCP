---
aliases:
  - ICMPv4
---
- a [[Network Layer Protocols]]
- Helps IPv4 to handle:
	- Error reporting
	- error correcting
	- host queries
	- management queries
- Used by hosts and routers to communicate network-layer information
# Message
- encapsulated in [[IP Datagram]]
	- Sets the protocol field to 1 to show the IP payload is an ICMP message
- Has an 8-byte header with two fields: Type and Code
- Two categories:
## Error-reporting messages
- Reports problems that a router or host may encounter
- Uses the source IP to send error message to the source
- Most common is *Destination Unreachable*(Type 3)
## Query messages
- Occur in pairs(request and reply)
- Help a host or network get specific information from a router or another host
- Used to:
	- prob or test if a host or router if alive and replying
	- One-way or Round-trip time
	- If the clocks are synchronized
- Used by:
	- Debugging tools like `ping` and `traceroute
# Debugging Tools via TCMP
- `ping`
	- To find if a host is alive and responding
	- based on two separate query messages: 
		- `echo request` 
		- `reply`
- `traceroute`/`tracert`
	- `traceroute` in Linux
	- `tracert` in Windows
	- Based on two [[#Error-reporting messages]]
		- Time Exceeded
		- Destination Unreachable
	- Also uses an Echo-request [[#Query messages]]
	- Trace the path of a packet from a source to the destination
	- It can find the IP addresses of all routers that are visited along the path
	- Usually set to check for the maximum of 30 hops