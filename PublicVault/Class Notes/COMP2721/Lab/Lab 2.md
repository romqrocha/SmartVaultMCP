# Exercise 1
A pipeline in a processor has 5 stages. Each stage takes the following  
amount of time to complete:  
• Stage 1: 150 nanoseconds  
• Stage 2: 120 nanoseconds  
• Stage 3: 100 nanoseconds  
• Stage 4: 180 nanoseconds  
• Stage 5: 140 nanoseconds  
## Question:  
1) What is the latency of this pipeline? (Latency is the time it takes for an  
instruction to pass through all stages.)  
```math
150ns + 120ns + 100ns + 180ns + 140ns
```
2) If the pipeline processes 1,000 instructions, how much time will it take to process all of them, assuming ideal pipelining where a new instruction enters the pipeline at each clock cycle?
```math
(150ns + 120ns + 100ns + 140ns) + (180ns * 999)
(150ns + 120ns + 100ns) + (180ns * 999) + 140ns
```

# Exercise 2
A computer system uses cache memory to speed up memory access. The cache hit rate is 95%, and the access time for the cache is 5 nanoseconds. 
1) If a cache miss requires accessing the main memory, which takes 100  
nanoseconds, calculate the average memory access time.
```math
( (5ms * 95%) + ( 100ms * 5%) ) / 100%
( (5ms * 95) + ( 100ms * 5) ) / 100
```

## Follow-up:  
If the hit rate decreases to 85%, how does that impact the average memory  
access time? 
```math 
( (5ms * 85%) + ( 100ms * 15%) ) / 100%
```

What does this tell you about the importance of a high hit rate in cache memory?
- It can dramatically affect the performance of your program overall.
- A small change in hit rate can also dramatically increase/decrease your average memory access time
