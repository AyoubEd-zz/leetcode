class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, d;
        while(i<j){
            d = nums[i]+nums[j];
            if(d==target) return {i+1, j+1};
            else if(d<target) i++;
            else j--;
        }
        return {};
    }
};
