/*
*https://leetcode.com/problems/contains-duplicate-ii
*
*Solution: map
*sliding window
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) && i-mp[nums[i]]<=k) return true; 
            mp[nums[i]]=i;
        }
        return false;
    }
};
/*bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int, int> st;
        for(int i=0;i<nums.size();i++){
            if(i>k) st.erase(nums[i-k-1]);
            if(!st.insert(nums[i]).second) return true 
        }
        return false;
    }
*/