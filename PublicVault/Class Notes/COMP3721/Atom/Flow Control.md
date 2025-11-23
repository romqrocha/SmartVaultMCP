# Data Link
- Anywhere one entity produces items and another consumes, there should be a balance between production and consumption rates
- If more frames are produced than consumed, the receiving end needs to be buffered
- Very small, 1kb
- Strategies:
	- The receiving data-link can drop the frame if the buffer is full
	- The receiving data-link can send feedback to sending data-link and ask it to stop or slow down
# TCP
> [!note] Avoid overwhelming the receiver
- Sender maintains a variable called "Receive Window"(`rwnd`)
	- Tells sender how much space the buffer has
	- Initial value is equal to the "Receive Buffer"(`RcvBuffer`)
- Sender limited amount of in-flight data to receivers `rwnd` value
- At receiver: $rwnd=RcvBuffer=[LastByteRcvd-LastButeRead]$
	- Simply: Assume the buffer at the other end is full of whatever you've sent until its acknowledged.