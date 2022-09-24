**1.** An int is stored in 32 bits.

**2.** An int is stored in 4 bytes.

**3.** The program will print: 
```
0
2
4
```
This is beacause the '>>' and '<<' functions shifts the bytes of the integer in the left, so '1 >> 1' will shitf all the bytes of the binary expression of 1 by one bit, making the expression goes from '00000001' to '00000000' (le right most bit have been 'erased'), on the other hand, 'x << y' shitfs the bits of the x binary expressions by y bits, making something like '10010100' become '1001010000' if y=2.

Shifting an int by 1 to the left is the same as adding a 0 at the rightmost position of its binary expression, thus every 1 that was at the n-th position (starting from the right) will become at the (n+1)-th position, making the whole value of the int be multiplied by 2.

**4.** In a unsigned char, we can store all the integers between 0 and (2^8 -1).

**5.** In a char, we can store all values from -(2^7) to (2^7 -1).

**6.** The leftmost bit in a int is reserved to represent the sign.