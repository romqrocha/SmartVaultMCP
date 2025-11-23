---
Class: COMP3760
Created: '[[2025 03 14]]'
tags: 
Reviewed: false
---
# Greedy Algorithms
> [!tip] "Always make the choice that looks best right now"
- For solving [[#Optimization Problems]]
- Construct a solution through a sequence of choices
- Always choose the best option available "right now"
- The hope is by choosing a *local* optimum at each step you end up at a *global* optimum
## Properties
- Feasible:
	- Must satisfy the problems constraints
- Locally optimal:
	- Best local choice among all feasible choices available on that step
- Irrevocable:
	- Once made, it cannot be changed during subsequent steps of the algorithm
```pseudocode
// In this example, we always take the largest possible piece of change
// hence 'Greedy'
Algorithm MakeChange(N)  
	sum = 0  
	coins = {} // set of coins to be returned  
	while sum < N do  
		choose the largest coin X with value <= (N-sum)  
		sum += X.value  
		coins += {X}  
	endwhile  
	return coins  
END
```
- Do not always give optimal general solutions to problems, but sometimes they do
# Minimum Spanning Tree
- AKA MST
- A subgraph of a [[Connected Graph | connected]], [[Undirected Graph|undirected]], [[Weighted Graph|weighted]] graph $G$ such that:
	- It includes all the vertices([[Spanning Graph|Spanning]])
	- It is Acyclic([[Tree]])
	- Total cost associated with the edges is the **minimum** among all possible spanning trees
- May not be unique
- On a complete graph:
	- Result is a tree, therefore connected
	- Connects all nodes
	- uses the minimum cost
- With an adjacency matrix:
	- Instead of 1 if connected, show weight
$T=MST(G)$

# Prim's Algorithm
- [[#Greedy Algorithms]] for [[#Minimum Spanning Tree]]
- Start with any one vertex
- Greedy choice at each iteration
	- Lowest-cost new edge you can add for all possible edges
	- New edge must not create a cycle

# Kruskal's Algorithm
- [[#Greedy Algorithms]] for [[#Minimum Spanning Tree]]
- Repeatedly add a minimum-weight edge that does not introduce a cycle
	- Literally look through the whole graph and just keep adding edges
	- Make small trees and keep going until they all connect
	- You can start with a blank adjacency matrix and keep updating the adjacency matrix
# Disjoint Subsets
- AKA Union-Find
- Collection of disjointed subsets
	- Any element can be in only one subset at a time
- Operations:
	- `MakeSet(x)` - creates a new subset with the element x
	- `Find(x)` - returns the subset that contains x
	- `Union(x, y)` - merges the subsets containing x and y
## Using [[#Kruskal's Algorithm]]
 - Maintain Disjoint Subset, $DS$ of vertices in tree $T$
 - Start with each vertex in a separate subtree
 - When edge(u, v) is added to $T$, $DS.Union(u, v)$
	 - If u and v are in the same subset, **do not add** as this will create a cycle
- Time complexity: $O(N^2logN)$
# Single-Source Shortest path
- AKA: SSSP
- Find the shortest path from a chosen vertex(the *source*) to every other vertex
# Dijkstra's Algorithm
- a [[#Greedy Algorithms]] for [[#Single-Source Shortest path]]
- Remember the best-known shortest distances, $d$, for all vertices from the starting vertex, $s$
	- initially infinity for all
- Choose the nearest(lowest total path cost) unprocessed vertex, $v$
- Look at all of its neighbors
- Update the shortest known path from $s$ to $v$
	- This is called "Relaxing"
- Repeat 1 
- Efficiency: $O(n^2)$
``` R
function Dijkstra(_Graph_, _source_):
     
    for each vertex _v_ in _Graph.Vertices_:
	    dist[_v_] ← INFINITY
	    prev[_v_] ← UNDEFINED
	    add _v_ to _Q_
    dist[_source_] ← 0
     
	while _Q_ is not empty:
		_u_ ← vertex in _Q_ with minimum dist[u]
		remove u from _Q_
		
		for each neighbor _v_ of _u_ still in _Q_:
			_alt_ ← dist[_u_] + Graph.Edges(_u_, _v_)
			if _alt_ < dist[_v_]:
				dist[_v_] ← _alt_
				prev[_v_] ← _u_
	
	return dist[], prev[]
```

# Coloring a Graph
- 