- Used to find the least cost between a source node, $x$, and a destination node, $y$ through some intermediary $a, b, c...$
- Assumes the source and intermediary nodes know the least cost between the intermediary nodes and the destination
- $c_{xy}$ is the cost between nodes $x$ and $y$
$D_{xy} = min\{(c_{xa} + D_{ay}), (c_{xb} + D_{by}), (c_{xc} + D_{cy})\}$
![[Bellman-Ford.png]]
- Compare the cost of getting to D through x and y to the cost of getting the C through x and a, then from C to D through a and y