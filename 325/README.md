## Maximum Size Subarray Sum Equals k

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

- - -

The main takeaway from this problem is the prefix sum trick. Computing the prefix sum basically makes turns the problem into the 2SUM problem.
Take for example: nums = [1, 1, -1, 5, -2, 3], k = 3
The prefix values will look like this: [1, 2, 1, 6, 4, 7]
Here we apply the 2 sum solution using a hash table and find that the 1, 4 corresponding to the indices 0, 4 satisfy our rule. Meaning that if we take the sum of [1, 1, -1, 5, -2, 3] and substract from it the sum of [1] we get [1, -1, 5, -2] which has a sum of 3.
