//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;
        int sp = 1, wp = 0;
        while(sp<n){
            if(nums[sp]!=nums[wp]){
                nums[++wp]=nums[sp];
            }
            sp++;
        }
        return wp+1;
    }
};