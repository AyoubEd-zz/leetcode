/* https://leetcode.com/problems/non-decreasing-array
 * Solution: get index of anomaly and check constraints.
 * ps: i was checking constraints before finding index wich resulted in complex code, sometimes having the index simplifies the process
*/

class Solution {
public:
    bool checkPossibility(vector<int>& A) {
        int n = A.size();
        if(n==1 || n==2) return 1;
        int p = INT_MIN;
        for(int i=0 ; i<A.size()-1 ; i++){
            if(A[i]>A[i+1]) {
                if(p>INT_MIN) return 0;
                p = i;
            }
        }
        if(p==INT_MIN || p==0 || p==A.size()-2 || A[p]<=A[p+2] || A[p-1] <= A[p+1]) return 1;
        else return 0;
    }
};
