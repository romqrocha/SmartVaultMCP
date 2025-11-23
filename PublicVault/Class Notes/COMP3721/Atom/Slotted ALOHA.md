- Like [[Pure ALOHA]], but time is divided into slots of $T_{fr}$ seconds and the station is forced to send only at the beginning on the time slot
# Throughput 
- $S = G * e^{-G} = 0.368 = 36.8\%$
- Maximum throughput $S_{max} = 0368$ when $G=1$
- $G = 1$ produces maximum throughput because [[Pure ALOHA#Vulnerable Time|vulnerable time]] is equal to frame transmission time
	- So if no other station generates a frame during the time this station generates a frame, we can guarantee this frame will reach its destination successfully.