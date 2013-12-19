/*
Use the following notations:
1) W: the selected bean is white
2) B: the selected bean is black

Use XX represents the 1st and 2nd selection results in an iteration. For 
example, BW means: the 1st selected bean is black and the 2nd selected bean is 
white. So the rules can encoded as:

WW = B
BB = B
BW = W
WB = W

Since the same rules are used in XOR bitwise operation, we can use the 
semantics of XOR. If the count if 1 bits are odd, the result of a series of 
XORs is 1. Otherwise, the result is 0. So if the count if white beans is odd, 
the final remaining bean is white. Otherwise, it is black.
*/
