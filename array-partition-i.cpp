/*https://leetcode.com/problems/array-partition-i/
 * Solution: Sort and pair largest with second largest element and so on.
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            i+=2;
        }
        return sum;
    }
};
