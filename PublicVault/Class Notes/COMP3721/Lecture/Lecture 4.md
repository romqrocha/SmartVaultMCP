---
Class: "[[COMP3721]]"
Created: "[[2025 01 17]]"
tags:
  - 0a84ff/DataComm
  - week/2
  - lecture
Reviewed: false
---
![[Wavelength]]

# Time & Frequency Domains
## Time-Domain plot
- What you expect to see when you see a waveform on a plot
## Frequency-Domain Plot
- Shows a bar on the frequency
	- Height of bar shows the peak amplitude of the signal
- A complete sine wave in the time domain can be represented by one spike in the frequency domain

# Composite Signals
- A signal made of many simple sine waves
- A single frequency sine wave is not useful in data communications, so we need to have many put together
- **Fourier** proved that any composite signal is a combination of simple sine waves with different *Frequencies*, *peak amplitudes*, and *phases

# Composite Non-Periodic Signals
- Decomposition gives an infinite number of simple sine waves with continuous frequencies (with real values)
	- e.g. Human Voice is a continuous range of frequencies between 0 and 4kHz
	- The signal propagated by AM/FM radio stations

# Bandwidth
- The difference between the Highest and Lowest frequencies in a composite signal

# Digital Signals
- Most are nonperiodic, so frequency and period are not suitable characteristics
- *Bit Rate* is used to describe digital signals
	- Defined as Bits per Second(bps) or Bytes Per Second(Bps)
- *Bit Length*
	- The distance one bit occupies on the transmission medium
	- Similar to wavelength
	- Propagation speed * bit duration
- Bit duration
	- 1/Bit Rate
	- e.g. 1/1Mbps = 1/$10^6$ = 1us

## Levels
- Refers to a specific state or value that a digital signal can have at a given point in time
- Digital signals have discrete levels/states, each represent a value or symbol
	- Usually associated with Voltage or Current levels
	- e.g. Binary has Low(0) or High(1). High could be 5v, low could be 0v
- More advanced digital systems can have Octal(8) or Hexadecimal(16) levels
- You can also encode multiple bits by using levels
	- e.g. 11 is level 4, 10 is level 3, 01 is level 2, 00 is level 1
	- $\text{Log}_2\text{n}$ bits are required to encode n bits
	```math
	n = 11
	ceil(log(n)/log(2))
	```

# Digital Signal as a Composite Analog Signal
- A periodic or nonperiodic digital signal is a **composite analog signal** with frequencies between 0 and infinity
- We use Fourier analysis to decompose a digital signal
- Periodic digital signals are rare in digital communications
	- Infinite bandwidth
	- discrete frequencies
- Nonperiodic digital signals
	- Infinite bandwidth
	- Continuous frequencies