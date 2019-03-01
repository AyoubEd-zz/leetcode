/* https://leetcode.com/problems/positions-of-large-groups
 * Solution: one pass and count
*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char prec; int start;int count = 0;
        S = S+ '0';
        vector<vector<int>> v;
        for(int i=0; i<S.size() ; i++){
            if(S[i]==prec) count++;
            else{
                if(count>=3) v.push_back({start, i-1});
                count=1;
                prec = S[i];
                start = i;
            }
        }
        return v;
    }
};
