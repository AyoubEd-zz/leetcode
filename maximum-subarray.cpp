//https://leetcode.com/problems/maximum-subarray
//Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<n;i++){
            if(sum<0) sum = nums[i];
            else sum+=nums[i];
            if(sum>max_sum) max_sum = sum;
        }
        return max_sum;
    }
};
