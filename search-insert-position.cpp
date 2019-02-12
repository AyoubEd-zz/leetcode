//https://leetcode.com/problems/search-insert-position/submissions/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        if(n==0) return 0;
        while(i<n){
            if(nums[i]>=target) return i;
            i++;
        }
        return i;
    }
};