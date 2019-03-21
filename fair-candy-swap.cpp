/* https://leetcode.com/problems/fair-candy-swap
 * Solution: Rather than Going through all the couples which will be O(n^2), we store elements of B in a bitset. Then we go through A looking for an element that would verify
 * the following equation iB = iA + (sumB-sumA)/2;
 * ps: using bitet is faster than using set and saves space.
*/
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
