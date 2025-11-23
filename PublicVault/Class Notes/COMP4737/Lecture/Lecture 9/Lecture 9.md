![[Part_10_memory.pdf]]
# Memory

## Memory Manager
>[!note] The part of the [[Operating System]] that manages the Memory Hierarchy
- Keeps track of which parts of memory are in use
- Allocate memory to [[Processes]] when they need it
- Deallocate memory when the processes are completed
### Without Memory Abstraction
- Old computers had no abstraction
- Every program can access and modify any location in memory

### With Memory Abstraction
- Started with Intel 80286
	- Had 2 modes; Real(Absolute) Address Mode, and Protected(relative) Virtual Address Mode
- To allows for multiple programs to be in memory, we need to solve Memory Protection and Memory Relocation. 
	- This was solved by giving each program an [[Address Space]]
## Memory Overloading
- When the currently running processes need more memory than is currently available
- Two methods for handling
### Swapping
- Bringing each process, in its entirety, from the disk and running it for a while before putting it back
- Idle processes are mostly on disk so they don't take up main memory when not running
- Creates holes in memory from unloading programs
	- Two ways to keep track of memory usage; Bitmaps and Link Lists
- This is really slow
### Virtual Memory
- Allows programs to run even when only partially loaded into main memory
- Each process has its own address space, broken up into chunks called [[Pages]].
	- Pages are a contiguous range of addresses
	- Pages are mapped(Loaded) to physical memory, like a [[Direct Mapped Cache]]
	- Not all pages need to be in physical memory at the same time to run the program
	- A piece of hardware, the [[Memory Management Unit]], maps the virtual addresses to physical memory addresses
	- The [[Page Table]] tracks the relationship between virtual and physical memory addresses
- A page in Physical Memory is called a Page Frame
- Pages and Page Frames generally have the same size
- OS initially loads the essential parts of the process: called the "Resident Set".
- Loads new pages if the process has a Memory Access Fault by trying to read outside the resident set.
- A large page size will cause more wasted space than a small one
- A small page size will cause more internal fragmentation
# Managing Free Memory

## Bitmaps
- Divides memory into allocation units, such as multiple KB, then list 0 if a unit is free or 1 if it is occupied.
- $k$ units leads to $k$ map bits
- Size of allocation unit is critical
	- smaller allocation unit means a larger bitmap
	- Larger allocation unit means smaller bitmap, but less allocation control.
## Link List
- Uses a Linked List to track chunks of memory.
- Each List Item contains:
	- P for Process or H for Hole
	- Address at which it starts
	- Length of section
	- Pointer to next
- If a process terminates and is adjacent to a Hole, it merges the two holes together
## Algorithms
- First Fit
	- Finds first Hole that is large enough to hole the process
	- Breaks the hole into a Process section and a new Hole
	- Fast because it searches as little as possible
- Next Fit
	- Like First Fit, but begins from where it left off last time
	- Slightly worse performance than First Fit
- Best Fit
	- Searches entire list and takes the smallest hole that it can fit on
	- Slower than First Fit
	- Tends to fill up memory with tiny, useless holes
- Worst Fit
	- Takes the largest available hole in hopes the new hole will be big enough to still be useful
- Quick Fit
	- Maintains separate lists for more common sizes
### Buddy System
- 
# Page Fault
> [!note] When a program tries to reference a page not stored in physical memory
- When the trap is raised, the CPU transfers control from the process to the OS Page Fault Handler
- OS will:
	1. save the state of the process
	2. Determine which virtual page caused the fault and figures out what it needs to do
	3. Loads or swaps the Physical Frame
	4. Updates the page table
	5. Restores the process state
	6. Resumes process execution
- Primary challenge is figuring out which Memory Frame to remove, if it needs to.
# Paging
## MMU
- Virtual address is split in 2; left side(high order) is for the Virtual page Number, and right side(low order) is the offset
- Goes to the index at the value of the Virtual Page Number
- Paste that value in front of the Offset to get the Physical Address
- This works really similarly to a Set-Associative Cache
## Speeding Up
- Issues: 
	- Mapping from virtual to physical address needs to be **FAST**
	- Is the virtual address space is large, the page table will also be large. 
	- Most programs tend to make a lot of calls to a small number of pages. 
- We can solve some of this by using a [[Translation Lookaside Buffer|TLB]] to directly map virtual addresses to physical addresses without going through the page table.
## TLB
- Each entry contains:
	- The virtual page number
	- Modification bit
	- protection code
	- validation bit(if entry in use or not)
## Misses
- Soft Miss: Not in TLB, but in Page Table
- Hard Miss: Not in TLB or Page Table. Requires disk access to load page into memory.
# Page Table
## Entry
- Size: 32 bits is common; the most important field is the Page Frame Number
- Present/Absent bit: if 1, entry is value, if 0, page fault
- Protection bits: What access is allowed.
- Modified bit: If 1, its been modified and should be written back to disk
- Referenced bit: Set whenever a page is referenced for read/write operations - "Is this page being used?"
- Caching Disabled bit: Allows caching to be disabled.