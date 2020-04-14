## Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

- - -

The idea behind this is like the well known prefix one. If we find a sum that we encountered already then we can conclude that if we remove the segment responsible for that first sum we can have a subarray with sum equal to 0, which means that it contains an equal number of zeros and ones.
