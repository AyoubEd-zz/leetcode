/* https://leetcode.com/problems/maximum-average-subarray-i
 * Solution: Prefic sum
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, mx = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            if(i<k) sum+=nums[i];
            else{
                mx = max(mx, sum);
                sum = sum+nums[i]-nums[i-k];
            }
        }
        mx = max(mx, sum);
        return mx/k;
    }
};

