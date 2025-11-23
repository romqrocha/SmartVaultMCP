- Every device has a [[Point-To-Point]] connection with every other device
- Since every device needs a dedicated link to every other device, we need $n(n-1)/2$ duplex links
	- This means every device needs $n-1$ I/O ports
# Advantages
- each connection carries its own load
	- This eliminates traffic problems
- Robust
	- If one link becomes unusable, the rest of the network is unaffected
- Privacy and Security
	- Each message only travels to the exact destination it is meant to go to