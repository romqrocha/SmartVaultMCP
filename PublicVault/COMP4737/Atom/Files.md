# Files
>[!quote] Logical units of information created by processes
- in [[Unix]] every file has a unique number - its i-number.
	- An index into a table of i-nodes
		- i-nodes are a [[Data Structure]]
		- One i-node per file
		- contains details about the file, such as who own the file, creation time, where its disk blocks are, etc.
- Before read/write, the permissions must be checked
	- System returns a small integer called a [[File Descriptor]] to use in subsequent operations
		- Will be negative if you don't have access to the file