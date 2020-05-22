## Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

- - -

The key insight in Kadane's algorithm is the fact that if the sum of a contiguous subarray is negative, it can't help us maximize the sum and thus we'll be better of without it.
This way we compute the cumulative sum and once this sum is negative we reinitialize it to 0.
