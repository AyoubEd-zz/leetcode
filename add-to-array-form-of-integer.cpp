/* https://leetcode.com/problems/add-to-array-form-of-integer
 * Solution: simulate the addition
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int d;
        for(int i=A.size()-1 ; i>=0 ; i--){
            d = (A[i]+(K%10));
            A[i] = d%10;
            K = (K/10)+(d/10);
            if(i==0 && K!=0){
                 A.insert(A.begin(), 0);
                i++;
            }
        }
        return A;
    }
};
