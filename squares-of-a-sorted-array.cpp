/*https://leetcode.com/problems/squares-of-a-sorted-array
*Solution: Two Pointers and fill from end
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j = A.size()-1 , k = A.size()-1;
        vector<int> v(A.size());
        while(i<=j){
            if((-A[i])>=A[j]){
                v[k] = A[i]*A[i];
                i++;
            }else{
                v[k] = A[j]*A[j];
                j--;
            }
            k--;
        }
        return v;
    }
};
