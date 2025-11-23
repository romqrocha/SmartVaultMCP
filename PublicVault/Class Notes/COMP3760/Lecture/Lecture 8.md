---
Class: COMP3760
Created: "[[2025 03 07]]"
tags:
  - 0a84ff/Algorithms
Reviewed: false
---
# Data Structure
- A particular way of organizing and storing data
	- Linear
		- Arrays
		- Linked Lists
		- Stacks
		- Queues
	- Set
	- Dictionary(Map)
	- Tree
	- Graph
	- Etc.
# Abstract Data Type
- The data structure is associated with a set of available operations
- A Data Structure + Set of operations = Abstract Data Type
	- A stack has Push, Pop, Peek
# Graphs
- Mathematic concept
- $G = (V, E)$
	- G = graph
	- V = a **Set** of Vertices
	- E = a **set** of Edges
- Some special types
	-  Connected graph
		- There is a path available between any two vertices
	- Cyclic graph
		- A graph containing at least one [[Cycle]]
	- Acyclic graph
		- A graph containing no [[Cycle]]
	- Tree
		- Any connected and acyclic graph
	- Complete graph
		- Every pair of vertices is connected by an edge
	- Weighted graph
		- Every edge has an associated value
# Trees
- Connected, Acyclic graph
- Common way to represent data in algorithms
- Can speed up algorithms in many natural problems
# Graphs
- Two common ways:
	- Adjacency Matrix
		- a | V | x | V | matrix
			- | V | -> The cardinality of V; the size of the set of V; the same as N
		- Cell i, j represents an edge from vertex i to j
	- Adjacency Lists
		- | V | linked lists
			- One for each vertex, shows all neighbors of that vertex
# Graph Traversal
- 
# Depth First Search
- Lists all vertices by moving **away** from the last vertex visited, as long as possible
- At a dead end, we go back until we find a new possible branch to explore and go down that branch
- Generally about visiting every possible vertex in a graph
- Often uses a **stack** of vertices being processed
```
Algorithm Depth_First_Search(Graph G)  
// Graph G = {V,E}  
	initialize visited to false for all vertices  
	for each vertex v in V  
		if v has not been visited  
			dfs_helper(v)
			  
function dfs_helper(Vertex v)  
	visit node v  
	for each vertex w in V adjacent to v  
		if w has not been visited  
			dfs_helper(w)
```
- Convention: 
	- Start at first node in natural order(A, 1)
	- Visit
	- Increment in natural order
- Typical Returns:
	- List of vertices in order visted
	- List of vertices in order of dead ends(When they were popped)
	- DFS tree
- Common uses:
	- Find the spanning tree of the a graph
	- Find a path between two vertices
	- Find a path out of a maze
	- Determine if a graph has a cycle
	- Find all connected components of a graph
	- Search the State-space of problems(AI)
- Efficiency
	- $O(N^2)$ for adjacency
	- $O(|N| + |E|)$ for adjacency lists
		- In worst case,$|E| = N$, so this is $O(N^2)$
		- So if you have a sparse graph, adjacency list is faster
		- otherwise, they're the same.
# Breadth First Search
- Navigate "Level-by-level" through a graph
- Convention:
	- Visit all neighbors that are the "same distance" from starting vertex
		- Visit immediate neighbors first
		- Then the neighbors of those vertices
		- etc.
	- Instead of a stack, BFS uses a **queue**
	- Edges that are in G, but not in the resulting BFS tree, are call *cross-edges*
- Efficiency:
	- Same as DFS
	- Returns one ordering of vertices since the order they are added/deleted from the queue is the same.
```
Algorithm Breadth_First_Search(Graph G)  
// Graph G = {V,E}  
	initialize visited to false for all vertices  
	for each vertex v in V  
		if v has not been visited  
			bfs_helper(v)  
	
function bfs_helper(Vertex v)  
	visit node v  
	initialize a queue Q  
	add v to Q  
	while Q is not empty  
		for each w adjacent to Q.head  
			if w has not been visited  
				visit node w  
				add w to Q  
	Q.dequeue()
```

# Solving problems with Graph Algorithms
- Two strategies
	1. Modify a known graph algorithm
		- Already done this
		- DPS and BFS did not perform output
	2. Use a known graph algorithm as a black box
		- Blackbox needs input, gives output
	- Or we can do both! 

- For a graph we need **vertices** and **edges**
	- Vertices represent *things* and edges represent *relationships between things*
# Topical Sort Problem
- Given a set of tasks with dependencies(Specifically precedence constraints; *eg. "Task a **must** be completed before task B*), find a linear ordering of the tasks that satisfies all dependencies
- V are the items(tasks)
- E are the dependencies (constraints) between tasks
	- An edge v->w means
		- w is DEPENDEND on V,
		- Task V must come before task W
## Algo1: DFS
1) Construct a directed graph to represent the problem
	- Verify its a [[Directed Acyclic Graph]]
2) Apply DFS to graph G
	- Starting at any vertex
3) The order in which vertices become dead ends is the REVERSE of a topological sort order

```
Algorithm TopoSort(G)  
	create an empty ArrayList A  
	create an empty TreeSet Candidates  
	add all v with inDegree=0 to Candidates  
	while Candidates is not empty  
		v = Candidates.first()  
		add v to A  
		for each vertex w adjacent to v  
			remove edge (v,w) from G  
			if w has inDegree=0  
				add w to Candidates  
		remove vertex v from G  
	if there are no vertices remaining in G  
		solution is in A  
	else  
		no solution exists
```