---
Class: COMP3721
Created: "[[2025 02 11]]"
tags:
  - 0a84ff/DataComm
Reviewed: false
---
### Radian to degree
$\text{deg} * \frac{\pi}{180\degree}$
# Bandwidth Utilization
- The wise of us available bandwidth
- Two broad categories:
	1. Multiplexing
	2. Spectrum spreading
## Multiplexing
- Combining several channels into one
- An analogy to a multilane highway
	- Different vehicles(multiple signals) that need to be transmitted
	- If its wide enough, we can have vehicles traveling in both directions
	- You can limit what kinds of vehicles go into which lanes to make each lane efficient and safe
		- Called Frequency Division Multiplexing(FDM)
### Definitions
- MUX = Multiplexer
- DEMUX = De-Multiplexer
- Link = Physical path
- Channel = portion of the link
### Frequency-Division Multiplexing (FDM)
- Acts on Analog signals
- Used for
	- AM/FM radio
	- Telephone
	- Television
- Split a spectrum into chunks, and assign each chunk to a signal(like radio stations)
- There are strips of unused bandwidth between each channel to prevent overlapping and interference
- Can be used if the bandwidth of a link, in hertz, is **greater** than the *combined* bandwidth of the signals to be transmitted

## Wavelength-Division Multiplexing (WDM)
- Analog multiplexing for *optical signals*
- Splitting/combining light sources are easily handled by a prism

## Time-Division Multiplexing (TDM)
- Digital multiplexing
- Allows several signals to share the bandwidth of a link in time
- Combines several low-rate channels into a high-rate one
- The data flow of each input connection is divided into units
- a unit can be a bit, char, or 'block' - it doesnt matter
- a round of data units from each connection is collected into a **Frame**
- if we have $n$ connections the frame is divided into $n$ time slots, and one slot is allocated for each unit.
```
A multiplexer combines four 100-kbps channels using a time slot of 2  
bits.  
1. What is the frame rate?  
2. What is the frame duration?  
3. What is the bit rate of the shared channel?  
4. What is the bit duration?  
```
```math
inputChannels = 4
channelRate = 100kb/s
timeSlot = 2b

frameRate = channelRate / timeSlot * 1 frame
frameDuration = 1 frame / frameRate
bitRate = channelRate * inputChannels
bitDuration = 1/bitRate
```

- The duration of the input unit is $T$
	- The time slot duration is $T/n$
	- The frame duration is $T$
### Synchronous TDM
- The data rate of the output link must be $n$ times the data rate of a connection to guarantee the flow of data
- Bit duration = $1/\text{BitRate}$
- Not efficient
	- If an input is not sending, that unit in the frame is left empty
#### Multilevel Multiplexing
- Used when data rate on an input line is a multiple of others
- Combines the smaller input lines into a faster/larger input line
![[DataComm_MultilevelMultiplexing.png]]
### Multiple-Slot Allocation
- Only works when your channel speeds are multiples of each other
- Opposite of Multilevel Multiplexing
- Divide the faster channel into slower multiple slower channels
- This lets the faster channel occupy more slots in the frame
![[DataComm_MultipleSlotAllocation.png]]
### Pulse Stuffing
- AKA Bit padding or Bit Stuffing
- Used when bit rates are not integer multiples
- Adds dummy bits to the slower channels to make their rates appear as fast as the fastest channel
 ![[DataComm_PulseStuffing.png]]
 ### Frame Synchronizing
 - The multiplexer adds a pattern of one-or-more bits to the beginning of the frame
 - Allows the demux to synchronize the income frames more accurately
  ![[DataComm_FrameSynchronization.png]]
- 