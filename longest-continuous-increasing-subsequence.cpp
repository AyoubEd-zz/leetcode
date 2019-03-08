// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;
        int mx = 0, j;
        for(int i=0 ; i<n-1 ; i++){
            j = i;
            while(i<n-1 && nums[i]<nums[i+1]) i++;
            mx = max(i+1-j, mx);
        }
        return  mx;
    }
};

