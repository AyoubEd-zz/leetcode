## Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
- - -


The first observation we can make is that if the heights of the vertical lines inside a container are shorter than the height of those defining container we don't need to consider them.

<p align="center"> 
<img src="https://imgur.com/T8ZXEZ5.png">
</p>


Hence, we will start with two pointers at the widest position(0, n), and keep narrowing down going only to taller vertical lines.

<p align="center"> 
<img src="https://imgur.com/kL8JCyi.png">
</p>


Now, we have to decide how are we going to increase or descrease the position of the pointers. 

<p align="center"> 
<img src="https://imgur.com/sRxTBlm.png">
</p>


If we are in the position (a, d), we have to check (a, c) (b, d) and (b, c). But here we find a second observation:

<p align="center"> 
<img src="https://imgur.com/89HItDy.png">
</p>

For the smaller vertical line (in this case a), there's no need to check (a, c) because S2 will be always bigger than S1. So we increase the first pointer and we'll be able to asses (b, c) and (b, d).





