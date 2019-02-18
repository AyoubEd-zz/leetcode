/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.29%)
 * Total Accepted:    343.8K
 * Total Submissions: 670.1K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * Solution : Boyer–Moore majority vote algorithm
 */
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int max = 0, count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0)
            {
                max = i;
                count++;
            }
            else if (nums[i] == nums[max])
                count++;
            else
                count--;
        }
        return nums[max];
    }
};
