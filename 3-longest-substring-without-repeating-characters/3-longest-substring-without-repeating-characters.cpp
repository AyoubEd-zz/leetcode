class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int maxLength = 0;
        int f = 0, s = 0;
        map<char, int> mp;
        for(int i = 0; i < str.size(); i++) {
            if(mp.count(str[i]) > 0 && mp[str[i]] >= s) {
                s = mp[str[i]] + 1;
            }
            mp[str[i]] = i;
            maxLength = max(maxLength, i - s + 1);
        }
        
        return maxLength;
    }
};