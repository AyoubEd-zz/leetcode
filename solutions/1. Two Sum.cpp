class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int s = nums[i];
            if(mp.find(s) != mp.end())
                return {mp[s], i};
            mp[target - s] = i;
        }
        return {0, 0};
    }
};
