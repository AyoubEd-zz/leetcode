/* https://leetcode.com/problems/third-maximum-number
 * Solution: use set
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        if(st.size()<3) return *st.rbegin();
        set<int>::iterator it = st.end();
        it--; it--; it--;
        return *it;
    }
};
