---
tags:
---

- Layer 3 of [[TCP-IP]]
- Responsible for [[Host]]-to-host delivery of **Datagrams**
- Provides Services to [[Transport Layer]]
	- [[Packetizing]]
	- [[Routing and Forwarding]]
	- Error Control
		- Checksum for the header, but not the whole datagram
	- Flow Control
		- Usually implemented by Transport Layer
	- Congestion Control
		- Usually implemented by Transport Layer
- Receives Services from [[Data-link Layer]]