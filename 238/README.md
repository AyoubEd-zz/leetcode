## Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

- - -

let's see the product for each element in the array this way:

arr = [1, 2, 3, 4]

           | 1 |  2 * 3 * 4
        1  | 2 |  3 * 4
    1 * 2  | 3 |  4
1 * 2 * 3  | 4 | 

We must note here that we cannot use division.

We can see that in order to compute the product needed for each element we can compute the prefix and and suffix independently.

Computing the prefix for each element is trivial, we keep variable called pref as we go through the array and compute our next pref each time.
But how can we compute the suffix without division? the little visualization above makes it obvious, we go through the array in the opposite direction. 
