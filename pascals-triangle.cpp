//https://leetcode.com/problems/pascals-triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows==0) return v;
        v.push_back({1});
        for(int i=0 ; i<numRows-1 ; i++){
            vector<int> vs={1};
            vector<int> vp = v[i];
            for(int j=1; j<vp.size() ; j++){
                vs.push_back(vp[j-1]+vp[j]);
            }
            vs.push_back(1);
            v.push_back(vs);
        }
        return v;
    }
};