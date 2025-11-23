# Backtracking Algorithm
> [!cite] A systematic way of trying out sequences of decisions until you find one that works
- Construct solutions one component at a time
- If a partial solution can be developed further without violating constraints, 
	- choose the first legitimate option for the next component
- If there is **no option** for the next component
	- Backtrack to replace the last component of a partial solution
- Think of the solutions as being organized in a tree
	- Each node represents the *state* at one stage of the solution
	- Root represents the initial state
	- Nodes at each level represent choices
	- called a [[State-Space Tree]]
![[Algorithms_StateSpaceTree.png]]
## Hamiltonian Cycles
- Start at any vertex, end at the starting vertex
- Successively build a path
- At each "level", try adding each remaining neighbor
- Backtrack at dead ends
# Branch and Bound Algorithm
- Set up a *bounding function*, which is used to compute a *bound* and a node on a [[State-Space Tree]] 
	- The bound is a possible best value we want out of our function
	- 