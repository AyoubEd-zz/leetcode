## Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

- - -

The key insight in Kadane's algorithm is teh fact that if the sum of contiguous sunarray is negative, it can help us maximizing the sum and thus we'll be better of without it.
