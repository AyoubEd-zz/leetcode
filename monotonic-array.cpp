/* https://leetcode.com/problems/monotonic-array/
 * Solution: two booleans for increasing and decreasing beahavior, only one have to be true.
*/
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int p=1, n=1;      
        for(int i=0 ; i<A.size()-1 ; i++){
            if(A[i]<A[i+1])n=0;
            else if(A[i]>A[i+1])p=0;
        }
        return p || n;
    }
};


