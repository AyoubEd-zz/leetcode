/*https://leetcode.com/problems/transpose-matrix
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> v(A[0].size(), vector<int>(A.size()));
        for(int i=0 ; i<A.size() ; i++){
            for(int j = 0 ; j<A[0].size() ; j++) v[j][i] = A[i][j];
        }
        return v;
    }
};
