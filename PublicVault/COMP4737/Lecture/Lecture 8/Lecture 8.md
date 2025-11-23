![[Deadlock]]
# Deadlock Avoidance
## Safe States
>[!note] There is a scheduling order in which every process can run to completion, even if all of them suddenly request all of their required resources immediately
- If no such guarantee can be given, its called an Unsafe State
### Bankers Algorithm
- Considers each request as it occurs, checking if it leads to a safe state
- Will only grant the request if it leads to a safe state
#### Multiple Resources
1. Look for a row, $R$, whose unmet resource need are **all** $\leq$ $A$.
	- If no such row exists, system will eventually deadlock.
2. Assume the process of row choses requests **all** the resources needed and finishes.
	- Mark that process as terminated, add its resources to $A$ vector
3. Repeat steps 1 and 2 until either all processes are terminated (We are in a safe state), or no process is left whose resource needs can be met(We are in an unsafe state/deadlock) 
## Attacking the Mutual-Exclusion Condition

## Attacking the Hold-and-Wait Condition

## Attacking the No-Preemption Condition

## Attacking the Circular Wait Condition

# Live-Lock
- Like a deadlock, because it stops all progress
- Threads may look active, but nothing is making actual progress
- Can be caused by 'Polite Processes', where you release all collected resources if you can't get all required resources
# Starvation
- When a process has really low priority and never gets to run
- Not deadlocked, but similar in that no progress can be made.
- Can be avoided using a first-come, first-serve resource allocation policy

# Resource
![[Resource]]$e_1$
