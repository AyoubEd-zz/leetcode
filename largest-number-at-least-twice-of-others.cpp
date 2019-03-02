// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) return 0;
        int max1 = INT_MIN, max2 = INT_MIN, idx;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>max2){
                swap(max1, max2);
                max2 = nums[i];
                idx = i;
            }else if(nums[i]>max1){
                max1 = nums[i];
            }
        }
        return (max2>=max1*2)?idx:-1;
    }
};
