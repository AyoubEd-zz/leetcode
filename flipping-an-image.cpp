/*https://leetcode.com/problems/flipping-an-image
 * Solution: Brute force with a little bit of prunning
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0 ; i<A.size() ; i++){
            int a=0, b=A[0].size()-1;
            while(a<=b){
                if(A[i][a]==A[i][b]){
                    A[i][a]=A[i][b]=((A[i][a]+1)%2);
                }
                a++;b--;
            }
        }
        return A;
    }
};
