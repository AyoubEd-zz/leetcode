/* https://leetcode.com/problems/degree-of-an-array
 * Solution: Keep count of frequency and right and left extremities.
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, pair<int, pair<int, int>>> mp;
        int mx=0, im;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])==0){
                mp[nums[i]] = make_pair(0, make_pair(i, i));
            }
            mp[nums[i]].first++;
            mp[nums[i]].second.second = i;
            if(mp[nums[i]].first>mx) {
                mx = mp[nums[i]].first;
                im = nums[i];
            }
            else if(mp[nums[i]].first==mx){
                if(mp[nums[i]].second.second - mp[nums[i]].second.first<mp[im].second.second - mp[im].second.first){
                    mx = mp[nums[i]].first;
                    im = nums[i];
                }
            }
        }
        return mp[im].second.second - mp[im].second.first+1;


    }
};
