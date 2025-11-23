---
Class: COMP2721
Created: '[[2024 09 27]]'
tags: 
Reviewed: false
---
# Mean Memory Access Time

- equals  (Cache Access Time) + (1- hit rate) * (Memory Access Time)
- written as C +( 1 - h ) * M
- Hit rate still considers the hit count of all levels above it
	- e.g. if i have L2 cache having 200 hits and L3 cache having 100 hits, I need to account for the hits that pass through L2 to get to L3

# Practice Questions

```math
#hitRate = 80%

1 + (1 - 0.8) * 60

```

```math
cache = 1m
hitRate = 90%
memoryAccessTime = 60m

cache + (100% - hitRate) * memoryAccessTime
```

```math
cache = 3ns
mainMemory = 80ns
hitRate = 70%

cache + (100% - hitRate) * mainMemory
```

```math
L1 = 4ns
L2 = 10ns
MM = 90ns

requests = 500
L1Hits = 300
L2Hits = 120
MMHits = requests - (L1Hits + L2Hits)

L1HitRate = L1Hits/requests
L2HitRate = L2Hits/requests
MMHitRate = MMHits/requests


L1 + ((L2HitRate + MMHitRate) * L2) + (MMHitRate * MM)

(500(4)ns + 200(10)ns + 80(90)ns) / requests

11200ns / 500

```

L1 = 3ns
L2 = 8ns
L3 = 12ns
MM = 100ns

826 requests
450 hits in L1
250 hits in L2
100 hits in L3
rest hits in MM

MM hits = 826 - (450 + 250 + 100)
		= 826 - (450 +350)
		= 826 - 800
		= 26

826 * 3ns + (250 + 100 + 26) * 8ns + (100 + 26) * 12ns + (26) * 100
^ / 826

```math

L1 = 3ns
L2 = 8ns
L3 = 12ns
MM = 100ns

requests = 826

L1_Hits = 450
L2_Hits = 250
L3_Hits = 100
MM_Hits = requests - (L1_Hits + L2_Hits + L3_Hits)

#MM hits = 826 - (450 + 250 + 100)
#		= 826 - (450 +350)
#		= 826 - 800
#		= 26

total = 826 * L1 + (L2_Hits + L3_Hits + MM_Hits) * L2 + (L3_Hits + MM_Hits) * L3 + (MM_Hits) * MM


total / requests
```


# Hard Disk Drives 
- Magnetic drives
- Store data in rings of bits, called tracks
	- "A ring of magnetic bits"
	- not a spiral groove, like a record or DVD
- The disks that store the data are called Platters
	- A single disk drive may have multiple platters
	- Each platter has a set number of tracks
	- All platters in a single disk have the same rings in the same position
	- The rings in the same position on a drive are connected in what's called a Cylinder
		- "An imaginary connection of the same track across disks"
	- Each track is cut into pieces called Sectors
		- "A slice of a track where the data actually is"
	- Sectors have gaps, headers and footers
		- Gap breaks up the header from body, and body from footer
	- Data is written in the same track spread across the different platters
		- e.g. A1->A2->A3
- Seek time
	- Time for the RW head to move to the desired track
- Rotational Latency
	- time for the desired sector to move to the RW head
## Time to read full drive
- move RW to track A
	- At best, already there
	- At worst, on furthest track
- wait for sector zero
	- on average, takes 1/2 Rotational Speed
- Read the data
	- 1 rotation x 3 platters
	- = 3 rotation
- Move to next track
	- wait full rotation for track 0
	- = 1 rotation
- repeat
