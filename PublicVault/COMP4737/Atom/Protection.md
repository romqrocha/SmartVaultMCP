# Protection
- [[Unix]] files are protected by assigning each file a 9-bit [[Protection Code]]
	- Three 3-bit fields
		1. Owner
		2. Members of owners group
		3. Everyone else
	- Three bits are for Read, Write, Execute
	- Known as `rwx` bits
	- `-rw-r--r--`
		- Owner can read and write
		- Members of the owners group can Read
		- Everyone else can Read
- In [[Linux]] the first bit is used to show what the file type is
	- – : regular file
	- d : directory 
	- c : character device file 
	- b : block device file 
	- s : local socket file 
	- p : named pipe 
	- l : symbolic link