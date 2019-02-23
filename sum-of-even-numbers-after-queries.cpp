/*https://leetcode.com/problems/sum-of-even-numbers-after-queries
 * Solution: Get the sum at the beginning and maintain it
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> v(queries.size());
        int sum = 0;
        for(int i:A){if(i%2==0)sum+=i;}
        for(int i=0; i<queries.size() ; i++){
            int val = queries[i][0], idx = queries[i][1];
            if(val%2==0 && A[idx]%2==0){
                sum+=val;
                A[idx]+=val;
            }else if(val%2!=0 && A[idx]%2!=0){
                A[idx]+=val;
                sum+=A[idx];
            }else if(val%2!=0 && A[idx]%2==0){
                sum-=A[idx];
                A[idx]+=val;
            }else {
                A[idx]+=val;
            }
            v[i]=sum;
        }
        return v;
    }
};
