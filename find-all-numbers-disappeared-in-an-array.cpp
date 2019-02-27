/* https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
 * Solution: -1 trick, you mark existing elements with -1 so you don't lose their value but know they are visited.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int cur;
        vector<int> v;
        for(int i=0 ; i<nums.size() ; i++){
            cur = abs(nums[i]);
            if(nums[cur-1]>0) nums[cur-1]*=-1;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]>0) v.push_back(i+1);
        }
        return v;
    }
};
