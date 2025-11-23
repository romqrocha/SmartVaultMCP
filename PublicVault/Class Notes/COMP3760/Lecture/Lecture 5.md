---
Class: COMP3760
Created: '[[2025 02 07]]'
tags: 
Reviewed: false
---
# Divide and Conquer
- Solve a problem that by making into smaller pieces that are identical to the current problem
- Often recursion
## VS decrease and conquer
- decrease and conquer has exactly 1 recursive call
- Divide and conquer has more then 1 recursive call
- With Divide and Conquer you need to solve **all** subproblems

## Analysis of Divide and Conquer
- What matters:
	1) Number of parts: `a`
	2) Size of each part: $n/b$
	3) Cost of combining subproblems(Extra work)
		- f(n) - a running time algorithm
### The Master Theorum
$n^{log_ba}$ 
- Big-O class of T(n) 
	- given T(n) is this: T(n) = $a*T(n/b) + F(n)$
	1) Compare $n^{log_ba}$ and F(n)
	2) Bigger one wins
		1) If $n^{log_ba} < F(n)$ then $T(n) = F(n)$
		2)  If $n^{log_ba} > F(n)$ then $T(n) = n^{log_ba}$
		3) If they're equal, $O(n^{log_ba}logn)$ 
- Example:
		$T(n) = 4T(n/2) + n$
		$\therefore a=4, b=2, F(n) = n$
		$n^{log_ba} \implies n^{log_{2}4} \implies n^2$
		$F(n)=n$
		$n^2 > F(n) \therefore T(n) \exists O(n^2)$
# Merge Sort
- 