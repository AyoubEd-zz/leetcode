## Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

- - -

We can get through all subarrays by calculating presums and storing them in a hash table. 
sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. We will surely have sum(0, i) already in our hash table once we've reached j, and then if it happens that sum(0, j) = k + sum(0, i), we can check the map for k - sum(0, j) and then we can incerement our count of subarrays.
