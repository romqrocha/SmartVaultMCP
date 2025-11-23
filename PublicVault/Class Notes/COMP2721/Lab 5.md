---
Class: COMP2721
Created: '[[2024 10 17]]'
tags: 
Reviewed: false
---
# Exercise 1
## Calculate Clock Cycle Period
```math
#Convert Mhz to unit-time

freq = 40 MHz
freq_Period = (1000 / 40) ns
```

## Total time from Address Stable until data is available
```math

freq = 25ns
wait = 1
tDS = 5ns
tAD = 2ns

delay = freq*(1.5 + wait)
t_max = delay - tAD - tDS

## Whoopsies, calculated for Time From Assert
#Calculate for tML
delay = freq*(1.5+wait)

tML = 4ns

tML_max = delay - tAD - tML - tDS


#calculate for tM
delay  = freq*(1+wait)
#We're missing tM, so we do some fucky shit
#tM = freq/2 - tAD - tML
tM = 6ns


tM_max = delay - tM - tDS

time_dataAvailable = tM_max < tML_max ? tM_max : tML_max
```

# Exercise 2
```math
freq = (1000/50)ns
wait = 1
tM = 6ns
tDS = 7ns

delay = (1+wait)freq
tM_max = delay - tDS - tM

delay = (1.5+wait)freq
# We have not been given enough information to calculate for tML
```

# Exercise 3
```math
#We're still missing information
```