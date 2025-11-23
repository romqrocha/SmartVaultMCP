
# Data Link
- The [[Data-link Layer]] packs bits into frames so each frame is distinguishable from another
	- Multiple frames per message allows us to avoid having to resend large chunks of data if something gets corrupted
## Frame Size
- Fixed
- Variable
	- Prevalent in LANS
	- We need a way to define the end of a frame
		- [[#Character-oriented approach]]
		- [[#Bit-oriented approach]]
	- We can do this with a **character**(byte)-oriented approach or a **bit** oriented approach
## Character-oriented approach
![[DataComm_VariableFrameLength_CharacterApproach.png]]
- This approach has an issue:
	- What if we use a newline for the flag and our string has newlines?
	- If this happens, the receiver THINKS it has found the end of the frame
	- We avoid this with **byte stuffing**, which is using an escape character to tell the receiver to treat the next chunk as data
	- Literally the same as escape characters in C or java
## Bit-oriented approach
- Becoming more popular
![[DataComm_VariableFrameLength_BitApproach.png]]
- Uses an agreed sequence of bits as the flag
- `01111110` is a common flag between most protocols
- If the flag exists within the data, we add an escape; same as with character-oriented
	- Common escape: If there are 5 1's in a row, add a 0 at the end of the 5 1's
	- This will be removed on by the receiver
![[DataComm_VariableFrameLength_BitStuffing.png]]