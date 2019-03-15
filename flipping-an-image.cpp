/*https://leetcode.com/problems/flipping-an-image
 * Solution: Brute force with a little bit of prunning
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A[0].size()-1;
        for(int i=0 ; i<A.size() ; i++){
            for(int j=0 ; j<(n+2)/2 ; j++){
                if(A[i][j]==A[i][n-j]){
                    A[i][n-j]=A[i][j]=!A[i][j];
                }
            }
        }
        return A;
    }
};
