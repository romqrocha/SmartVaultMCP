
>[!NOTE] The following Hamming codeword was created using EVEN parity. Are there errors? If so, where? What was the original data word suppose to be?
>0100 1011 0101 1

```
dataword: 0 1 0 0  1 0 1 1  0 1  0  1   1
index:    1 2 3 4  5 6 7 8  9 10 11 12  13
isPower:  x x   x        x

dataword: 0 1 0 0  1 0 1 1  0 1  0  1   1
index:    1 2 2 4  4 4 4 8  8 8  8  8   8
			  1    1 2 2    1 2  2  4   4
					   1         1      1
					   
1 =           0 +  1 + 1 +  0 +  0 +    1 = 3 = 1
2 =           0 +    0+1 +    1 +0        = 2 = 0
4 =                1+0+1 +         1 +  1 = 4 = 0
8 =                         0+1+ 0+1 +  1 = 3 = 1

1 0 0 1 vs
0 1 0 1

error on 1 & 2 bit
So the error is on bit 3, which affects bit 1 and 2

dataword: x x 1 0  1 0 1 1  0 1  0  1   1
index:    1 2 2 4  4 4 4 8  8 8  8  8   8
			  1    1 2 2    1 2  2  4   4
					   1         1      1
					   
1 =           1 +  1 + 1 +  0 +  0 +    1 = 4 = 0
2 =           1 +    0+1 +    1 +0        = 3 = 1

fixed dataword: 
0110 1011 0101 1
original codeword:
1101 0101 1
```
