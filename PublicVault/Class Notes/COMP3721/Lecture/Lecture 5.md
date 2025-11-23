---
Class: "[[COMP3721]]"
Created: "[[2025 01 21]]"
tags:
  - 0a84ff/DataComm
  - week/3
  - lecture
Reviewed: false
---

# Digital Signal Transmission

## Baseband
- Digital signal is not converted to analog
- Requires a **low pass channel**
	- The lowest frequency contained in the channel is zero
	- Helps preserve the shape of the digital signal
- If the signal is below a certain level, it also requires a low-pass channel
	- A low pass channel has an upper bound
- LAN networks are Baseband
- The required bandwidth is proportional to the bitrate
	- if you want to send bits faster, you need more bandwidth
## Broadband (Modulation)
- Changes the digital signal to analog
	- Modulation
- Requires a **bandpass** channel
	- Allows signals between two frequencies **or** has a non-zero start
## Impairment
- Imperfection of transmission media
### Attenuation
- Loss of signal over distance
- Due to energy requirements to overcome the resistance of the medium
- We can use an [Amplifier] to return the signal to original strength
- Losing something
### Distortion
- Undesired change in shape of your signal
- Can occur in a composite signal made of different frequencies
- Signal components at the receiver have phase differences from what they had at the signal
- Mixing things up
### Noise
- Unwanted amplitude or frequencies in the signal
- Types:
	- Thermal
		- Motion due to heat can cause extra signals not originally sent
	- Induced
		- External components that create EM waves
		- From other sources of signal, like a microwaves effect on Bluetooth headphones
	- Crosstalk
		- When two channels/signals interfere with each other
		- Example: When two radios attempting to talk at the same time cancel each-other out
	- Impulse
		- A spike of power, or a short circuit
- Gaining something
#### Signal to Noise ratio(SNR)
- High SNR, the signal is less corrupted by noise
- Low SNR, the signal is more corrupted by noise
- Since its a ratio of two powers, we use dB
```
SNR = average signal power(watts) / average noise power(watts)
```
- If we have no noise, we will have an infinite SNR
- SNR is a ratio of what is wanted to what is **not** wanted
- We need SNR to find theoretical bit rate limit

# Decibel
- The relative strengths of two signal, or a single signal at two different points
- Negative: The signal has been attenuated/lost energy
- Positive: The signal has been amplified
```
p(power) = V(volts)^2/R(resistance)
```
- 3dB is 50%
	- Because decibels are logarithmic, its growth/decay is exponential/logarithmic

# Data Rate Limits
- Als called bit rate or capacity
- Indicates how fast we can send data, in bps, over a channel
- Relies of 3 factors
	- The available bandwidth
		- Relates to the physical attributes of the channel
	- The number of signal levels
	- The quality of the channel(how noisy)
- There are two theoretical formulas for calculating bit rates
	- Nyquist(for noiseless)
	- Shannon(for noisy)
## Nyquist
- Theoretical max bit rate for noiseless channel
	- Bit Rate = $2 * Bandwidth * log_2Levels$
	- Levels are usually in power of 2, because you cant use decimal value levels. e.g. if you need 21.2 levels, you actually need 22.
## Shannon
- In reality, no channel is noiseless
- Shannon Capacity indicates the *theoretical* highest data rate
- Capacity = bandwidth x log$_2$(1 + SNR)
	- Capacity is bps
- No matter how many levels you have, you cannot achieve a data rate higher than the capacity

# Bandwidth
- Can have 2 meanings
	- In Hertz
		- The frequency range in a composite signal
		- the range of frequencies a channel can pass
	- in bits Per Second
		- called Bit Rate
		- Number of bits Per Second a link/network can transmit
- The relationship between them is not 1:1, but an increase in hertz will lead to an increase in bps

# Bandwidth-Delay Product
- the number of bits that can fill the link
- Is important if we need to send data in bursts and wait for acknowledgement between bursts
- Is the maximum amount of data in transmission at any given time
	- 2 x bandwidth x delay for full-duplex

# Transmission Modes
- Digital information can be sent in Parallel or Serial
- Parallel is what busses use on a CPU, lots of small cables each transmitting the same data at the same time.
![[DataComm_ParallelTransmission.png]]
- Advantages:
	- Speed
- Disadvantage:
	- Cost

- Serial transmission uses 1 line
	- Reduces cost of transmission by a factor of n(number of bits per second)
- 