# Hierarchical Routing
- Each ISP is considered an [[Autonomous System]]
# IPv6
- 128-bit address(16 bytes)
- Main reason for migration from IPv4 to IPv6 is the [[Address Depletion]] of IPv4
## Notations
- Binary:
	- Used when the addresses are stored in computer
- Colon Hexadecimal
	- `FEF6:BA98:7654...`
	- Leading zeros can be removed
		- `00FF -> FF`
	- If consecutive sections include only zeros, replace with a double colon(only once per address)
		- `FDEC:0:0:0:0:BBFF:0:FFFF -> FDEC::BBFF:0:FFFF`
- CIDR:
	- 
## Address Types
1) Unicast
	- Indicates a single interface(Host/router)
	- first $n$ bits used for Global Routing
		- Used by global routers to route the packet
		- Recommends 48 bits
	- middle $m$ bits used for Subnet identifier
		- Recommends 16 bits
	- last $q$ bits used for Interface Identifier
		- Allows a relationship between [[IP Address]] and [[Link-Layer Address]]
		- Recommends 64 bits
2) Anycast
	- Indicates a group of computers that share an address
	- The packet is delivered to only **ONE** member of the group
3) Multicast
	- Indicates a group of computers that all share a single address
	- **ALL** members receive a copy of the packet
## Strategies for Transition
### Dual Stack
- A host runs [[IPv4]] and [[#IPv6]] simultaneously until all of the internet uses IPv6
- Indicate what version to use with the Datagram Protocol field
### Tunneling
- When hosts using IPv6 want to communicate, but the packet travels across a region that uses IPv4
- IPv6 packet gets [[Encapsulation|Encapsulated]] in an IPv4 packet
- Value of the Protocol field is set to 41
### Header Translation
- Will be necessary when the majority of the Internet has transitions
- Sender wants to send IPv6, but receiver only understands IPv4
- We convert the header of the IPv6 packet to an IPv4 header