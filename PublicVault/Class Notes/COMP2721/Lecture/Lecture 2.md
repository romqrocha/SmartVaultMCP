---
Class: COMP2721
tags:
  - ComputerArchitecture
Reviewed: false
---
## Definitions:
- Clock
	- Anything that can be turned on and off
- Clock Cycle
	- In a computer, very regular intervals
	- Clocks operate in powers of 10
		- 100MHz is 100 * 10^6
		- This is the Clock Frequency
	- Period is 1/Frequency, so 1/1Million = 1 microsecond
	- 1GHz = 1Billion = 100 * 10^9
	- Slowest stage in the pipeline(?)
- Clock Speed
	- 1GHz CPU
		- 1 billion rising and falling edges per second
		- 1 rising edge per nano( 10^-9 )second
		- This means you can **possibly start** one instruction each second
			- e.g. The clock cycle of a TV show is 30 minutes, which means you can start a new TV show every half hour, but not that TV shows are finished in 30 minutes.
			- With parallelism, like a movie theatre, a clock cycle could be 5 minutes, so you can trigger a new movie start every 5 minutes.
				- It does **NOT** mean movies are 5 minutes long
- Interpreter
	- Any software program(Like a VM) that FDE the instructions of another program.
		- The output of this is another program that is simpler to run, but this takes time
	- cheaper than having hardware run the original
	- also cheaper than having the hardware do the conversion(Interpretation)
# CPU Organization
- Register File
	- Some general-purpose register
	- Some special-purpose registers
		- Program Counter(PC)
			- Holds the memory address of the next instruction to the FDE
		- Instruction Register(IR)
			- Holds the currently executing instruction
	- Registers need to be constantly fed with data.
## FDE
1) PC Gives an address
2) Retrieve information from address using a bus
3) Decode instruction
4) Move appropriate pieces of data into Input registers
5) Execute instruction using ALU
6) Move output into output register
7) Decide if you want to keep that information in the register or move it to main memory

## Wish-List for speeding up execution
- All instructions should be directly executed by Hardware
	- Complex and expensive
- Issue instructions as fast/often as possible
	- Complex, expensive, and physical limitations(signal speed through wire)
- Instructions should be easy to decode
	- Backwards compatibility, same sized instructions
- Only LOAD and STORE instructions should reference main memory
	- Cant avoid going to RAM
- Provide lots of registers
	- Expensive
- End goal: Prevent the CPU from starving

# RISC
- <u>R</u>educed <u>I</u>nstruction <u>S</u>et <u>C</u>omputer
	- Fewer and simpler instructions than CISC
	- e.g. 3+3+3+3 = 12

# CISC
- <u>C</u>omplex <u>I</u>nstruction <u>S</u>et <u>C</u>omputer
	- More, and more complex, instructions
	- Implement the most common instructions directly in hardware, so no interpretation is required - even the complex ones.
	- e.g. 3 * 4 = 12

Modern computers are a mix: RISC with some CISC
# CPU Design Principles
![[CPU_CacheRequests.png]]
- CPU requests 1 Word at a time from Main Memory
	- It doesn't not know the Cache exists
- Cache checks if it has the Word
	- If it does, it sends that Word to the CPU
	- If its not, the Cache gets a BLOCK of words around the requested word
		- Because programs tend to run in order, this increases the odds of the cache grabbing the next instruction without needing to being asked
	- The Cache requests **blocks** of words at a time

## Locality
- Two types:
	- Spatial
	- Temporal
### Principle of Spatial Locality
- "Words physically located in memory near a recently requested word are likely to be requested soon"
- The tendency for programs to execute in order
- Grabbing blocks of memory when a word is requested is using the principle of Spatial Locality to increase the odds of the cache having the next batch of instructions ready to go
- Only works on a small time scale
- Is a guess - but an educated guess!

### Principle of Temporal Locality
- Over some small interval of time, the same data, the same instructions, and the same address are likely to be reused
	- Like a for-loop or while-loop
- Because of this, the cache tries to keep recent words and will not let them get evicted

# Pipelines
- "A set of multiple hardware devices that FDE in parallel and in series, in order to maximize instructional bandwidth"
- Analogous to an assembly line
	- An assembly line makes things simpler, cheaper, and faster
- The primary one is the Fetch-Decode-Execute Pipeline
- Instructional Latency
	- The total time an instruction spends in the pipeline, from start to finish
		- e.g. 5min/car
- Instructional Bandwidth
	- The number of instructions finishing per unit time
		- 1/slowestStageTime
		- e.g. 1car/min
- Superscalar Architecture
	- Adds extra hardware at the slowest stages to remove bottlenecks
- A longer/deeper pipeline can increase bandwidth, and may lengthen, shorten, or not affect latency