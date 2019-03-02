/* https://leetcode.com/problems/find-pivot-index
 * Solution: Prefic sum
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int sum1 = 0, sum2;
        sum2 = accumulate(nums.begin(), nums.end(), 0);
        sum2-= nums[0];
        for(int i=0;i<nums.size();i++){
            if(sum1 == sum2) return i;
            sum1+=nums[i];
            if(i==nums.size()-1) sum2 = 0;
            else sum2-=nums[i+1];
        }
        return -1;
    }
};
