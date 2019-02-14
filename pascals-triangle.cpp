//https://leetcode.com/problems/pascals-triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if numRows==0) return v;
        v.push_back({1});
        if numRows==1) return v;
        v.push_back({1, 1});
        if numRows==2) return v;
        for(int i=2;i numRows;i++){
            vector<int> vp(i+1);
            vp[0]=1; vp[i]=1;
            for(int j=1; j<=(i+1)/2; j++){
                vp[j]=v[i-1][j-1]+v[i-1][j];
                vp[i-j]=vp[j];
            }
            v.push_back(vp);
        }
        return v;
    }   
};