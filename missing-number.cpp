class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int d = nums.size();
        int sum = d*(d+1)/2;
        int i=0, j=d-1, s = (d%2==0)?0:nums[d/2];
        while(i<j){
            s+=nums[i]+nums[j];
            i++;j--;
        }
        return sum-s;
    }
};