class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long x = pow((long double)2, k);
        if(s.length() < x) return false;
        
        unordered_set<string> st;
        for(int i = 0; i <= s.length() - k; i++) st.insert(s.substr(i, k));
        
        return st.size() == x;
    }
};