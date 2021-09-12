class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(const auto& c: s) {
            if(!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};