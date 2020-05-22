## Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

- - -
<br>
We compute the cumulative product. If the product is positive we update the sum. For the negative products we keep track of the maximum negative product so far, in order to maximize cp / max_neg.<br>
When we encounter a zero we start a new cumulative product, and we reinitiliaze max_neg. 
