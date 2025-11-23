# IPv4 address
- 32 bit address
- Uniquely and universally defines the connection of a [[Host]] or [[Router]] to [[The Internet]] 
	- Uniqueness: Each address defines one, and only one, connection to the internet
	- Universality: The addressing system must be accepted by any host that wants to be connected to the internet
- Is the address of the **connection**, not the host or the router
	- When the device is moved to another network, the IP address may be changed
	- If a device has two connections to the Internet, it has 2 IP addresses
## Address Space
- Total number of addresses used by the protocol
- for $b$ bits per address, the address space is $2^b$
- IPV4 has $2^{32}$ addresses
## Notations
1. Binary
2. Dotted-decimal notation -> 192.168.1.254
3. Hexadecimal notation -> Used in network programming
	- 192.168.1.254 = C0 A8 01 FE
## Hierarchy
- The 32 bits is hierarchical and divided into two parts
- Prefix is $n$ of the 32 bits
	- Defines the network
- Suffix is $(32-n)$ bits
	- Defines the connection to the network
![[IPv4_Hierarchy.png]]
# Classless Addressing
- Old class-based systems had problems with [[Address Depletion]]
- Short term solution
	- same address space as [[#IPv4 address|IPv4]]
	- Each organization gets a fair share of addresses
	- [[Network Address Translation]]
- Motivated by
	- Address Depletion of IPv4
	- The emergence of [[ISP]]
		- An ISP is granted a large range of addresses
		- They then subdivide the addresses and assign them to customers
- Address is divided into *Variable Length Blocks*
	- Prefix in the address defines the *block*(network)
	- Suffix defines the node(device)
- Restriction: Number addresses in a block need to be a power of 2
		- $2^1, 2^2, etc$
- Size of the network is **inversely proportional** to the size of the length of the **prefix**
	- Small prefix means large network
	- Large prefix means small network
	- A larger prefix means there are LESS devices on the network
- An organization can be granted one block of addresses
## Classless Interdomain Routing
- AKA CIDR
- Prefix Length(AKA Mask), $n$, is added to the address and separated by a slash
- Notation is referred to $CIDR$, pronounced Cider, or Slash Notation
- $byte.byte.byte.byte/n$
- 12.24.76.8/8
# Extracting Address Information
- Given any address in a block, we should extract 3 piece of information
	1. The number of addresses: $N=2^{32-n}$
	2. First address in the block
		- Keep the $n$ leftmost bits, set the $32-n$ rightmost bits to all 0
	3. Last address in the block
		- Keep the $n$ leftmost bits, set the $32-n$ rightmost bits to all 1
# Network Address
- First address in a block is called the Network Address
- Important since it is used in [[Routing and Forwarding|routing]] the packet to its destination
- **NOT USABLE**
# Address Mask
- Aka Subnet Mask
- A 32 bit number in which the $n$ leftmost bits are set to 1 and the rest are set to 0
- 167.199.170.82/27 subnet mask is  /27 
	- 11111111.11111111.11111111.11100000 = 255.255.255.224
# Block Allocation
- Responsibility of a global authority called ICANN
	- Internet Corporation for Assigned Names and Numbers
- Assigns large blocks of addresses to an ISP/large organizations
- Two restrictions are applied to the allocated block:
	1. Number of requested addresses $N$ needs to be a power of 2
		- If not a power of 2, they round up to the next power of 2
	2. Decimal value of the first address needs to be divisible by the number of addresses in the block
		- $FirstAddress = prefixInDec * 2^{32-n} = prefixInDec * N$
# Subnetting
- The process of creating a [[Subnetwork]]
- Creates more levels of hierarchy
- Organization/ISP is granted a range of addresses may divide the range into subranges and assign each subrange to subnetwork
# Special Addresses
1. This-Host address: 
	-  Only address in the block 0.0.0.0/32
	- Used when a host needs to send an IP [[Datagram]] but doesn.t know its own address to use as the source address
2. Broadcast Address: 
	- Only address in the block 255.255.255.255/32
	- Used when a [[Router]] or [[Host]] needs to send a datagram to all devices in a network
	- Routers in the network block the packet having this address as the destination, so the packet cannot travel outside the network
3. Loopback Address: 
	- The block 127.0.0.0/8
	- A packet with one of the addresses in this block as the destination address never leave the host
	- Used for testing software, running services, etc.
4. Private Addresses
	- 4 blocks: 10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16, and 169.254.0.0/16
5. Multicast Addresses
	- 224.0.0.0/4
# Forwarding of IP Packets
- To deliver the packet to the next hop, which can be the final destination or an intermediate connecting device
- [[IP Protocol]] was originally designed to be connectionless
- Forwarding is based on the Destination Address of the [[Datagram]]
	- This is the traditional approach, still prevalent today
## Destination Based Forwarding
- Requires a host or router or have a [[Routing and Forwarding#Routing Table|Routing Table]]
- In [[#Classless Addressing]], one row of information is added to the table for each block involved:
	1. Mask
	2. Network Address
	3. Interface(port) number
	4. IP address of next router
	- Common for 1 and 2 to be combined
- Forwarding table needs to be searched based on the [[#Network Address]]
> [!note] Network Address is the first address in a block!
## Address Aggregation
- As the number of rows in a forwarding table increases, the time to search the table increases
- Aggregation is used to alleviate the problem
	- Blocks of addresses are combined to create larger blocks
	- Router can be done based on the [[#Hierarchy|prefix]] of the larger block
	- A big advantage of CIDR
## Longest Mask Matching
- A routing principle in [[#Classless Addressing]]
- States the forwarding table is sorted from the **longest** mask to the **shortest** mask
- When a router receives an IP packet, it compares the destination IP bit-by-bit with the prefixes in the routing table
	- The prefix with the most matching bits is the prefix the router will use
## Hierarchical Routing
SLIDE 41!