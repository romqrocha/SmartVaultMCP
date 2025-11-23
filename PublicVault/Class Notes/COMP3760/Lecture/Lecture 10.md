# Dynamic Programming
> [!cite] Don't repeat calculations you could have remembered
- A [[Space-Time Tradeoff]]
	- You remember each calculation as you do them and store them
	- The overhead of checking if something has been calculated is lower than the overhead of running the calculation multiple times
- **Remembering** recursively-defined solutions to sub-problems and using them to solve the problem
- A good idea if many of the sub-problems are repeats
- is NOT [[Divide and Conquer]]
	- Divide and Conquer don't repeatedly do the exact same work; each one of the calls should be on different data
## Process
1) Decompose problem into smaller **equivalent** sub-problems
2) Express solution in terms of sub-problems
3) Use a table to compute optimal value bottom-up
4) Find optimal solution based on steps 1-3
## Examples
```
// Top-Down example fib using dynamic programming
fib (n) {  
	// memo is an array of results
	if memo[n] exists, return it  
	if n < 2  
		return n  
	else  
		f = fib(n-1) + fib(n-2)  
		memo[n] = f // Memoize the result
		return f  
}
// Bottom-up example of fib using dynamic programming
fib (n) {  
	memo[0] = 0;  
	memo[1] = 1;  
	for i ← 2 to n do  
		memo [i] = memo[i-1] + memo[i-2]  
	return memo[n]  
}
```
```
ALGORITHM RobotCoinCollection(C[1..n, 1..m])
// Input: Matrix C with element equal to 1 or 0 for cells
//			with and without coins, respectively
// Output: Maximum number of collectable coins
F = [n, m]
F[1, 1] = C[1, 1]
for j=2 to m do:
	F[1, j] = F[1, j-1] + C[1, j]
for i = 2 to n do:
	F[i, 1] = F[i-1, 1] + C[i, 1]
	for j = 2 to m do:
		F[i, j] = max(F[i-1, j], F[i, j-1]) + C[i, j]
return F[n, m]
```
# Transitive Closure
> [!question] What nodes are reachable from other nodes?
- AKA Reachability
- AKA Warshall's Algorithm
- a [[#Dynamic Programming]]
- Given an Unweighted [[Directed Graph]], find all paths that exist from vertices $v_i \text{ to } v_j$ for all $1\leq(i, j)\leq n$
	- Note: Problem is always solved with an adjacency matrix graph
- Idea: Create a new graph where every **edge** represents a path in the original  
	1) Select row 1 and column 1
		- For all i, j: if $(i, 1) = 1$ and $(1, j) = 1$, set $(i, j) = 1$
	2) Select row 2 and column 2
		- For all i, j: if $(i, 2) = 1$ and $(2, j) = 1$, set $(i, j) = 1$
	3) Repeat for each row/column
- Why is this Dynamic?
	- It finds the path from simpler subproblems by using the returned matrix from the subproblem as input for the next problem
![[Algorithm_DynamicProgrammingExample.png]]
## Examples
### Warshall's
-  $O(n^3)$
```R
Warshall(R[1..n, 1..n])  
	for k ← 1 to n {  
		for i ← 1 to n {  
			for j ← 1 to n {  
				if ( R[i,k] == R[k,j] == 1 ) {  
					set R[i,j] ← 1  
			}  
		}  
	}  
}
```
# All-Pairs Shortest Paths
- AKA APSP
- is [[#Dynamic Programming]]
- Given a *directed* [[Weighted Graph]], find the shortest path from any vertex $v_i$ to any other vertex $v_j$ for all $1\leq (i, j) \leq n$
	- Always solved with a matrix graph
- Used in games for finding shortest paths before planning movement
## Examples
### Floyd's Algorithm
- Like [[#Warshall's]]
- is [[#Dynamic Programming]]
- The real key change:
	- Warshall's says if $(i, k) == (k, j) == 1$ then set $(i, j) = 1$
		- i.e. if you can get from i to k and from k to j you can get from i to j
	- Floyds says if $(i, k) + (k, j) < (i, j)$ then set $(i, j) = (i, k) + (k, j)$
		- i.e. if i-j-k costs less then the best known path from i to j, update the best known path
- Process:
	1) Select row 1 and column 1
		- For all i, j: if $(i, 1) + (1, j) < (i, j) \rightarrow (i,j) = (i, 1) + (1, j)$
	2) Select row 2 and column 2
		- For all i, j: if $(i, 2) + (2, j) < (i, j) \rightarrow (i,j) = (i, 2) + (2, j)$
	3) Repeat for each row/column
- Final matrix gives shortest paths from any i to j
```R
Floyd(G[1..n, 1..n]) 
	for k ← 1 to n {  
		for i ← 1 to n {  
			for j ← 1 to n {  
				cost_thru_k ← G[i,k] + G[k,j]  
				if ( cost_thru_k < G[i,j] ) {  
					set G[i,j] ← cost_thru_k  
				}  
			}  
		}  
	}
```
- How is this Dynamic?
	- The "sub-problem" is that it's finding the shortest paths that use vertices 1..k as a hopping point
	- One new vertex($k$) is added at each step
	- After each step you have matrix $D_k$ that gives the current best distance through those vertices