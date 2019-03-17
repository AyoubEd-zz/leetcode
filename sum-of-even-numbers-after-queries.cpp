/*https://leetcode.com/problems/sum-of-even-numbers-after-queries
 * Solution: Get the sum at the beginning and update it
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum=0, index, val;
        vector<int> v(queries.size());
        for(auto a:A){
            if(a%2==0) sum+=a;
        }
        for(int i=0 ; i<queries.size()  ; i++){
            index = queries[i][1];
            val = queries[i][0];
            if(A[index]%2==0) sum-=A[index];
            A[index]+=val;
            if(A[index]%2==0) sum+=A[index];
            v[i] = sum;
        }
        return v;
    }
};
