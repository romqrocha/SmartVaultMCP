# Timesharing
>[!quote] Their model was the electric system - when you need electric power, you stick a plug in and the wall, and within reason, as much power as you need will be there. 
- Each user has an online terminal
- Its unlikely ALL users want to be doing something at the same time
- This means the [[Central Processing Unit|CPU]] can be allocated to the jobs that are requested, and work on larger batch jobs in the background when the CPU would otherwise be idle.
	- #question Does this mean Timesharing uses [[Multiplexing#Space|Space sharing]] as well
- Used by [[Cloud Computing]]
# Modeling Usage
- If a process spends a portion of its time($p$) waiting for IO to complete, with $n$ processes in memory at once, the probability that all $n$ processes are waiting for IO(which means the CPU is idle) is $p^n$. CPU utilization is then given by $1-p^n$