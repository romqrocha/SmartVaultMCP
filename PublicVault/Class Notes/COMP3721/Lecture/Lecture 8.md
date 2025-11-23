---
Class: "[[COMP3721]]"
Created: "[[2025 01 28]]"
tags:
  - 0a84ff/DataComm
  - week/4
  - "#lecture"
Reviewed: false
---
# Coding Schemes
- Common Characteristics:
	1. [[#Signal element vs Data Element]]
	2. [[#Data rate vs Signal rates]]
	3. [[#Bandwidth]]
	4. [[#Baseline Wandering]]
	5. [[#Self-Synchronization]]
	6. [[#DC Components]]
# Signal element vs Data Element
- Data Elements
	- are the smallest entity of data
	- bits, for a computer (0 or 1)
	- *what we need to send*(logically)
- Signal Element(Symbol, state)
	- Carries data element
	- Is the shortest unit(timewise) of a digital signal
	- *what we CAN send*(physically)
- Ratio `r`
	- The number of data elements carried by each signal element
# Data rate vs Signal rates
- Data Rate = bit rate
	- an increase in data rate -> an increase in the speed of transmission
- Signal Rate(Modulation Rate, Pulse Rate, Baud Rate)
	- How many signal elements send in 1 second
	- Measures in Baud(Baud per Second)`Bd`
	- A decrease in signal rate means a decrease in the bandwidth requirement
- *A goal in modern data comms in to increase the data rate while decreasing the signal rate*
- The relationship between Data Rate and Signal Rate
```
S = N/r
s = Signal Rate
N = data Rate
r = Ratio
```
- Depends on the value of R and the pattern of the data
- Generally interested in Average Case
	$S = c * N * 1/r$
- $c$= case factor
# Bandwidth
- The actual bandwidth of a non-periodic digital signal is continuous with an infinite range
- Effectively the bandwidth is finite
- The Baud Rate(Symbols per Second), *not the bit rate*, determines the required bandwidth
- The bandwidth(Range of frequency) is proportional to the signal rate
	- We can replace S(Signal Rate) with B(Bandwidth)
	 $S = c * N * 1/r$
 	 $B = c * N * 1/r$
	 $\therefore B = c*N/r$
	 $\therefore N=1/c*B*r$
	- $N$ is the data rate of the channel
- A signal with $L$ levels can carry $log_2L$ bits *per level*
- If each level corresponds to one signal element, and we assume the average case ($c=1/2$), then we get the following:
$$
N_{max} = \frac{1}{c}*B*r = 2 * B * log_2L
$$
# Baseline Wandering
-  Baseline:
	- The running average of the received signal power
- Baseline Wandering:
	- A drift in the baseline caused by a long string of 0's or 1's
	- This makes it difficult for the receiver to decode the signal correctly
	- A good encoding scheme needs to prevent baseline wandering
# Self-Synchronization
- The clock ticks of the sender and receiver must be synchronized, otherwise the start and ends of the bits will be offset
- Self-synchronizing data signals include timing information in the data being sent
- Transitions/changes in the signals voltage can be used to alert the receiver to the beginning, middle, or end of a pulse.
	- It can use these signals to reset the clock

# DC Components 
- The mean amplitude of the waveform
- With no DC component, a signal has an average amplitude of 0
- if mean amplitude is 0, there is no DC bias
	- This can be called DC balanced or DC free waveform
- 0hz is DC because it doesn't change
# Line Encoding Schemes
## Unipolar(On-off Keying)
- Unipolar means 1 side of the time axis(One Magnetic Pole?)
- All signal levels are on side of the time axis - either > 0 or < 0
- Traditionally *Non-Return-To-Zero*(NRZ) scheme
	- It doesn't return to zero at the middle of the bit.
- Positive voltage defines bit 1, zero voltage defines bit 0
- Called on-off keying because its like pushing a button to turn the voltage on and off
## Polar
- Polar means it exists on both sides of the time axis, but not at zero
- NRZ-L(Level)
	- Two levels of voltage amplitude
	- Positive voltage for level 0
	- Negative voltage for level 1
- NRZ-I(Invert)
	- Change or lack of change of voltage determine the value
	- No change for 0
	- Change for 1
- Has problems
	- DC Components
		- Power density is high around frequencies close to zero
		- because we don't go to zero, our DC component moves around because the median changes over time.
	- Baseline wandering
		- Potentially long sequences of 0 or 1
	- No self synchronization
		- Because it might have long sequences of 0 or 1
- Manchester
	- Popular in IR/RFID/NFC
	- Zero is move down, 1 is move up
	- Because it must always be moving to be read, it keeps the DC component at 0
- Differential Manchester
	- No change, next bit is 1
	- Inversion, next bit is 0
	- inverts across zero between clock ticks to keep the DC component at 0.
- Both Manchester
	- Have self-synchronization
		- Because they always move in the center of a signal, you can sync your clock to that movement
	- No baseline wander
	- No DC component
	- Drawback
		- Signal rate is higher when compared to some other polar schemes
## Bipolar/Multilevel Binary
- Polar, but split in half.
	- Contains high, low, and zero
- One voltage is always at 0, the other is alternating between positive and negative
- Alternative Mark Inversion(AMI)
	- 0 is no voltage
	- 1 is alternating positive and negative
- Small DC component