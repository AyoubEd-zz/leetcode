/*https://leetcode.com/problems/squares-of-a-sorted-array
 *Solution: Two Pointers and fill from end
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j = A.size()-1, k = A.size()-1, pi, pj;
        vector<int> v(A.size());
        while(i<j){
            pi = A[i] * A[i];
            pj = A[j] * A[j];
            if (pi < pj) {
                v[k] = pj;
                j--;
            } else {
                v[k] = pi;
                i++;
            }
            k--;
        }
        v[k] = A[i]*A[i];
        return v;
    }
};
