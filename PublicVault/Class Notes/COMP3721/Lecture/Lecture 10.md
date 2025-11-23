---
Class: COMP3721
Created: "[[2025 02 07]]"
tags:
  - 0a84ff/DataComm
  - week/5
Reviewed: false
---
# Pulse Code Modulation(PCM)
- A technique for Analog-To-Digital conversion
1) Sample 
2) Quantize
3) Encode
## Sampling
- Find Sample Frequency
	- Must be at least 2 times the highest frequency
		- Called the Nyquist Rate
		- We do this so we capture the peak AND the valley of the sine wave
	- More then that is a waste of resources, but the extra data can be used in more complicated procedures
- With a low-pass analogue signal, the bandwidth is the highest frequency
	- Signal frequency starts at 0 and goes to n, so n is the bandwidth
- With a Bandpass analogue signal
	- Bandwidth < highest frequency
## Quantization
- Maps the actual voltage of a analogue signal to a discrete integral value
### Quantization error(Noise)
- $-\triangle/2 <= \text{quantization error} <= \triangle/2$ 
### Uniform Quantization
- Only optimal with uniformly distributed signals
- Height of delta is not fixed
	- greater near lower amplitudes, less near higher amplitudes
## Encoding
- The simplest format is to convert a digital number to a binary number
- first we select the number of levels to get the number of bits per sample: $n = log_2L$
- We can then calculate the bits per second, or the *bit rate*: sampling rate * bits per sample

## PCM Bandwidth
$B_\text{min} = n_b * B_\text{analog}$
- The minimum bandwidth of a digital signal is $n_b$ times greater than the bandwidth of the analog signal

# D2A & A2A
## Why?
- D2A: To convert a digital signal to analog, for music when being played or your voice through a microphone
- A2A: Converting analog signals to different mediums, such as audio to EM waves and back for Radio
## Carrier Frequency
- A high-frequency signal produced by the sending device
	- Acts as a base for the information signal
	- Carrier signal is a simple sine wave
	- Receiver is tuned to the frequency of the carrier
	- #question/answered Is this AM/FM? Yes!

# Note: $d$ is equal to 1 for all these slides.
Don't ask why. It just is. Remember it.
## D-to-A conversion
- Modify any of the characteristics of a sine wave(amplitude, frequency, and phase) based on information in the digital data
	- Called Modulation or Shift-Keying
## Amplitude Shift Keying (ASK)

### Binary ASK(BASK)
- Also called On-Off Keying(OOK)
- Adjusts the peak amplitude to 0 for one value
	- e.g. a digital 1 means the Carrier stays at its amplitude, a digital 0 sets the amplitude to 0
- The modulation process produces a non-periodic composite signal
- Bandwidth is proportional to the signal rate
## Frequency Shift Keying(FSK)
- The *frequency* of the carrier is  to represent data
- The modulated frequency is:
	- Constant for the duration of one signal element
	- Changes for the next signal element if the data element changes
- Amplitude and Phases are constant
### Binary FSK(BFSK)
- Two carrier frequencies are used
	- If data element is 0, $f_1$ is used.
	- If data element is 1, $f_2$ is used.
- The difference between the two frequencies is $2\triangle\text{f}$
- The distance between each frequency is based on 
### Multilevel Frequency Key(MFSK)
- More than 2 frequencies are used, but its not common

## Phase Shift Keying(PSK)
- The phase is changed to represent two or more different signal elements.
- peak amplitude and frequency remain constant
- More common than ASK or FSK
- Less susceptible to noise than ASK
	- It is harder for noise to effect the phase than the amplitude
- Needs more specialized hardware to distinguish
### Binary PSK(BPSK)
- Two signal elements are used
- One has a phase of $0\degree$
- other has a phase of $180\degree$
![[DataComm_BPSK.png]]
- Same bandwidth has BASK, but less than BFSK
## Quadrature Amplitude Modulation(QAM)
- Combines ASK and PSK
- Dominant method of D-A modulation
	- Used in 802.11 Wi-Fi standard
- Uses two carrier signals
	- One in phase
	- the other *quadrature*
		- out-of-phase by $90\degree$
	- different peak amplitude for each carrier
- Same minimum bandwidth requirement as ASK and PSK
# Constellation diagram
- Representation of signal modulated by a digital modulation scheme
- X is 0 to 180
	- Labeled as $I$ because its In Phase
- Y is 0 to 90
	- Labeled as $Q$ because its Quadrature
- Length is amplitude
- Angle is phase: $0 \text{ to } 2\pi$ or $0\degree \text{ to } 360\degree$

# Analogue-to-Analogue modulation
## Amplitude modulation
- Carrier signal is modulated so that its amplitude varies with the changing amplitudes of the modulating signal
- Bandwidth of the modulated signal is **twice** the modulated signal and covers a range centered on the carrier frequency
## Frequency Modulation
- Frequency is modulated to follow the changing amplitude of the modulated signal
- Peak amplitude and phase remain constant
- Total bandwidth required for FM can be determined from the bandwidth of the modulating signal
### FM Radio
- Encoded in stereo
- Bandwidth of a signal in stereo is ~15kHz
- FCC allows for 200kHz for each channel
### Phase Modulation
- Not used