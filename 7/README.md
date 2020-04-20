## Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

- - -

This is an easy question. but there is a pitfall related to overflow. While it seems that I managed to get a my solution accepted just using this condition: rev > 1<<31 - 1 (I take the sign off at the begining). A more rigorous consition setcan be obtained with following analysis:

the problem sets the integer range to [−2^31,  2^31 − 1]

The line that causes the overflow problem is rev = rev * 10 + x%10. 

if rev > (2^31 - 1)/10 or rev < -2^31/10, it is automatically an overflow.
if rev == (2^31 - 1)/10 == 2147483647 / 10 == 214748364 then rev * 10 = 2147483640. So x%10 should not exceed 7.
A similar calculation for negative integers tells as that x in the case rev == -2147483648, x%10 should be strictly greater than -8.

