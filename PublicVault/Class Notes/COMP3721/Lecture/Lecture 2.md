---
Class: "[[COMP3721]]"
Created: "[[2025 01 10]]"
tags:
  - 0a84ff/DataComm
  - "#week/1"
  - lecture
Reviewed: false
---
# Type of Connections

## #fc #definition Point-to-point link
- A dedicated link between two devices
- Entire capacity is reserved for communication between the two devices

## #fc #definition Multipoint
- More than two devices sharing a single link
- Capacity of the channel is shared
	- Spatially shared: Each user gets n amount of the data throughput
	- Timeshared: Each user gets 100% of the data throughput 1/n of the time

# Topology
- The geometric representation of all links and linking devices
## Mesh
- Every devices has a dedicated [[#fc definition Point-to-point link|point-to-point]] link to every other device
### Advantages:
- Each connection gets maximum data throughput
- Robust
- Secure
- Easy to identify faults and faults are isolated
### Disadvantages
- Difficult installation
- expensive
- Wiring take take a lot of space

## Star
- Each device has a dedicated [[#fc definition Point-to-point link|point-to-point]] link to a central controller, called a hub
### Advantages:
- Less expensive installation than Mesh
- Easier installing/reconfiguring
- Less cabling
- Still robust
	- You can identify if a single **link** is broken without shutting down a network
- Faults are isolated
### Disadvantages
- Single point of failure
- More cabling required than bus or ring

## Bus
- Uses a [[#fc definition Multipoint|Multipoint connection]]
	- One long cable that works as a backbone to link all the devices
- Drop Lines and Taps connect each node
- There are limits on the number of taps a single bus can support, and the distance between taps
	- Each tap weakens the overall signal
### Advantages
- Easy to install; just requires a backbone and a tap
- Few cables
### Disadvantages
- Difficult to reconnect or add new devices
- Difficult to isolate faults

## Ring
 - Each devices gets a dedicated [[#fc definition Point-to-point link|point-to-point]] connection with the two devices adjacent to it
 - Each devices has a repeater
### Advantages
- Easy to install and reconfigure
- Easy of fault isolation
### Disadvantages
- Unidirectional traffic
	- A break in the ring can disable the whole network

# Network Types

## Local Area Network(LAN)
- Usually privately owned
- Connects hosts in a single office, building, or campus
- Limited size, both in physical area and number of connections
- Each host has a unique identifier
- Called WLAN if Wireless
## Wide Area Network(WAN)
- Wide *geographic* area, like a town, state, country, or even the world
- Interconnects network devices like switches, routers, and modems
	- Does not connect Hosts like a LAN does
- Two types:
	- Point-to-point is a single switch directly connected to another switch
	- Switched WAN is multiple networks connected by multiple switches
## internetwork
- When two or more networks are connected, usually by a WAN

# The Internet
## End Systems/Hosts
- A node that sits at the edge
- Hosts run applications, e.g. web browsers
## Access Network
- The network that physically connects an end system to the first router
## Provider Network
- National/Regional ISP, like Telus
## Backbones
- International ISP, who connect all their networks together to form internetworks, like Bell or AT&T
## Peering Points
- A shortcut from one network to another, also a connection between Backbones
# Internet Standards
- A tested specification and formalized regulation that must be followed
- created and published by IETF(Internet Engineering Task Force)
- Allows for interoperability between systems

# Protocol
- A set of rules
- Defines:
	- What is communicated
	- How
	- When
	- With who
# Network Layers
- First principle: Each layer must perform two opposite tasks
	- Read/Write
	- Encode/Decode
	- Talk/Listen
- Second: Two objects under each layer at both sites should be identical

# Protocol Layering
- Enables us to divide the complex task of communication into smaller and simpler tasks
## Advantages:
- Separate services from implementation
- Simpler and less expensive intermediate systems
- Modularity
# TCP/IP
- A protocol suite used in The Internet
- Hierarchical protocol made up of 5 layers
## Application(Layer 5)
- Communication for a network application(Like WhatsApp)
- PDU name: Message
- protocols:
	- IMAP
	- SMTP
	- HTTP
	- FTP
	- Telnet
	- DNS
## Transport(Layer 4)
- Process-to-process delivery
- Almost always implemented in software
- PDU Name: Segment
- protocols:
	- TCP
	- UDP
	- SCTP
## Network(Layer 3)
- Host-to-host communication
- Also called "IP layer"
- PDU Name: Datagram/Packet
- Protocols:
	- IP
	- ICMP
	- DHCP
## Data Link(Layer 2)
- Data transfer between neighboring network elements/devices
- PDU(Protocol Data Unit) name: Frames
- Protocols: 
	- Ethernet
	- Wifi(802.11)
## Physical(Layer 1)
- Carries the bits from one node to another
- Bits received in a frame from the data-link are transformed to signals to be sent through the transmission medium
- Link dependent: Different depending on medium(Copper wire/fiber optic, etc)