/* https://leetcode.com/problems/max-consecutive-ones
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, mx = 0;
        for(int i:nums){
            if(i==1)count++;
            else{
                mx = max(mx, count);
                count = 0;
            }
        }
        return max(mx, count);
    }
};
