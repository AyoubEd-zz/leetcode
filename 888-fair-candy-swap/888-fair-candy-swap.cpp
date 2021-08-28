class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1=0, sum2=0, val;
        bitset<100001> st;
        for(int a:A){
            st.set(a);
            sum1+=a;
        }
        for(int b:B) sum2+=b;
        val = (sum1-sum2)/2;
        
        for(int b:B){
            if(b+val>0 && b+val<= 100000 && st.test(b+val)) return {b+val, b};
        }
        return {0, 0};
    }
};