//https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0 || (n==1 && nums[0]==val)) return 0;
        if(n==1) return 1;
        int sp = 0, wp = 0;
        while(sp<n){
            if(nums[sp]!=val){
                nums[wp++]=nums[sp];
            }
            sp++;
        }
        return wp;
    }
};