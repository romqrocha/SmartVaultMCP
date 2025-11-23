- Can be divided into sub-subnetworks
	- A sub-subnetwork can be divided into sub-subnetworks
	- and so on
# Designing
- Assumptions:
	  $N$: The total number of addresses granted to an [[ISP|Organization]]
	  $n$: prefix length
	  $N_{sub}$: Assigned number of addresses to each subnetwork
	  $n_{sub}$: Prefix length for each subnetwork
- To guarantee proper operation of the subnetworks:
	1. Number of addresses in each subnet should be a power of 2
	2. The prefix length for each subnetwork should be found as follows
		- $n_{sub}=32-log_2N_{sub}$
	3. Starting address in each subnet should be divisible by the number of addresses in that subnet
		- Can be achieved if we first assign addresses to larger subnets
- Should be carefully designed to enable the routing of packets
- After designing, the information, such as first and last addresses, can be found using the same process as in [[Class Notes/COMP3721/Lecture/Lecture 16#Extracting Address Information|Extracting Address Information]]
# Example:
> [!question] An organization is granted a block of addresses with the beginning  address 14.24.74.0/24. 
> The organization needs to have 3 subblocks of addresses to use in its three subnets: one subblock of 10 addresses, one subblock of 60 addresses, and one subblock of 120 addresses.  
> Design the subblocks.

1. Total addresses = $2^{32-24} = 2^{8} = 256$
	- Address start at 14.24.74.0/24, end at 14.24.74.255/24
2. Largest block: 120 addresses. 120 is not a power of 2, 128 is next power of 2.
	- Subnet mask is $32-log_2 128 = 32-7 = 25$
	- First address is 14.24.74.0/25, last is 14.24.74.127/25
3. Next largest: 60 addresses. 60 is not a power of 2, 64 is next power of 2.
	- Subnet mask is $32-log_2 64 = 32-6 = 26$
	- First address is 14.24.74.128/26, last is 14.24.74.191/26
4. Smallest: 10 is not a power of 2. 16 is the next power of 2.
	- Subnet mask is $32-log_2 16 = 32-4 = 28$
	- First address is 14.24.74.192/28, last is 14.24.74.207/28