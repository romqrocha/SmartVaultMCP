# Deadlock
>[!note] When multiple [[Processes]] are all waiting for an event from one or more of the waiting Processes.

- Can be software or hardware based
- When working with multiple [[Lock Variable|Lock]] for accessing [[Resource]], make sure all functions that attempt to lock and release the resources in the same order to avoid deadlocks
- To have a resource deadlock, there are 4 conditions that must be met:
	1. [[Mutual Exclusion]]
		- Each resource is either assigned to exactly **one** process, or is available
	2. Hold and Wait
		- Processes that got resources earlier can get new resources
	3. No Preemption
		- Resources that were previously given to a process cannot be forcibly taken away.
	4. Circular Wait Condition
		- There must be a circular list of two or more processes, each of which is waiting for a resource held by the next member in the chain
>[!note]- Detection Algorithm- Single Resource of each type
>For each node, $N$, in the graph, perform the following 5 steps with $N$ as the starting node
>1. Initialize $L$ to an empty list and designate all arcs as unmarked
>2. Add current node to the end of $L$
>	- If current node appears twice in the list, graph contains a cycle and algorithm terminates
>3. From given node, see if there are unmarked outgoing arcs
>	- If so, go to 4. Else, go to 5.
>4. Pick unmarked outgoing arc at random. Mark it, go to node, and go to step 2.
>5. If this is the starting node, graph does not contain cycles. Else, dead end. Remove, go to previous node, and go to step 3.

- [ ] #task Review [[Part_9_Deadlock.pdf#page=42&selection=6,0,20,4|Deadlock with multiple resources]

>[!note] Detection Algorithm- Multiple Resource of each type
>1. Look for unmarked process, $P_i$, for which the $i$-th row of $R$ is $\leq A$
>2. If a process is found, add the $i$-th row of $C$ to $A$, mark the process, and go back to step 1.
>3. Else, terminate the algorithm
## Recovery
### Preemption
- Take the resource from another process
- Depends on the nature of the resource(if the resource is [[Preemptable]])
### Rollback
- Write the process state to a file periodically so it can be restarted later. 
- If a deadlock occurs, rollback some processes
### Killing processes
- Crude, but simple
- With a little luck, the other processes will be able to continue. If not, just keep killing.
- It is best to kill a process that can be rerun from the start with no negative effects