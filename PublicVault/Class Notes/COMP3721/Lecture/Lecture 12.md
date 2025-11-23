---
Class: COMP3721
Created: "[[2025 02 14]]"
tags:
  - 0a84ff/DataComm
  - week/6
Reviewed: false
---
# The Internet
- A combination of networks connected by devices(routers or switches)
- A packet traveling from host-to-host needs to pass through all these networks
>[!note] We encapsulate and decapsulate each datagram at each intermediate node
Each link may be using a different protocol with a different frame format
Even if one link and the next use the same protocol, we need to en/de-capsulate because the link-layer addresses are normally different
## Services
- The data-link layer is located between physical and network layers
	- Provides services **to** the network
	- Receives services **from** the physical
### Provided By
- Framing:
	- Encapsulating the datagram into a frame before sending it
- Flow Control:
	- Controlling the rate of producing rates to the rate of consumed frames
- Error detection and correction
### Sublayers
- Data Link Control (DLC)
- Media Access Control(MAC)
	- Only deals with issues specific to Broadcast(shared) links

### MAC address 
- Media Access Control Address
- Link-layer address = Physical address = MAC
- Most common MAC addresses are 48 bits(6 bytes) represented as 12 hex digits, grouped in 2 hex
- First 6 hex are the maker of the device(3 bytes)
- remaining 3 bytes are unique
### Switch as layer 2 device
- Link-layer switch is involved in the Data-link and Physical layers
- Switch connects devices within a network
- Unlike a router, it sends the frame to the single device it is intended for
	- May be sent to another switch, router, or a computer
### Address Resolution Protocol (ARP)
- Maps an IP address to a logical-link address
- A host or router needs to run the ARP program all the time in the background
- A sending device sends a **request** to all devices on the network asking who has a specific MAC address and IP address 