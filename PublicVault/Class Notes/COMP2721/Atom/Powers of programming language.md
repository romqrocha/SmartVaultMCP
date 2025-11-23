
# Calculating the difference in time for levels
- Compare how many instructions it takes for 1 language to do the amount of work of another
- Consider a multilevel computer in which all the levels are different. Each level has instructions that are m times as powerful as those of the level below it; that is, one level **r** instruction can do the work of _m_ level **r - 1** instructions. If a level-1 program requires k seconds to run, how long would equivalent programs take at levels 2, 3, and 4, assuming *n* level r instructions are required to interpret a single r + 1 instruction?
n=interpretations/instruction
- The number of interpretations required to convert 1 HLL -> 1 equivalent lower level instruction
m = Power
- How many LLL instructions are required to do the same work as one HLL instruction
k= known time value
kl = level who's time value we know

l = level we want to calculate for

r =  the difference in levels, or r-kl

time = $k * n^{r}/m^{r}$
or
time = $k * n^{l-kl}/m^{l-kl}$

level 4: k seconds * (interpretations * interpretations * interpretations) / (power * power * power)
level 3: k seconds * (interpretations * interpretations) / (power * power)
Level 2: k seconds * interpretations / power 
Level 1: k seconds

This means that:
- The more interpretations are needed, the more time is needed
- The more power there is, the less time is needed

> [!NOTE] Multilevel computer question
> Consider a multilevel computer in which all the levels are different. Each level has instructions that are five times as powerful as those of the level below it; that is, one level y instruction can do the work of five level y − 1 instructions. If a level-two program requires two seconds to run, how long would equivalent programs take at levels four and five, assuming seven level y instructions are required to interpret a single y + 1 instruction? Always show your work.

```math
m = 5
n = 7

k = 2s
kl = 2

l = 4
r = l - kl

k*(n^(r)/m^(r))

l = 5
r = l - kl

k*(n^(r)/m^(r))

```
> [!NOTE] From quiz 1
> Consider a multilevel computer in which all the levels are different. Each level has instructions that are 6 times as powerful as those as the level below it; that is, one level p instruction can do the work of 6 level p - 1 instructions. If a level-4 program requires 2.2 years to run, how long would the equivalent programs take at levels 2 and 5, assuming 11 level p instructions are required to interpret a single p + 1 instruction?

```math
k = 2.2year
kl = 4
m = 6
n = 11

l = 2

k*(n^(l-kl)/m^(l-kl))

l = 5

k*(n^(l-kl)/m^(l-kl))

```

