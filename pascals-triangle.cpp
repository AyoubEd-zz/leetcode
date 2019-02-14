//https://leetcode.com/problems/pascals-triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows==0) return v;
        v.push_back({1});
        if(numRows==1) return v;
        v.push_back({1, 1});
        for(int i=1 ; i<numRows-1 ; i++){
            vector<int> vp = v[i];
            int n = vp.size();
            vector<int> vs(n+1);
            vs[0]=1;
            for(int j=1; j<=(int)(n+1)/2; j++){
                vs[j]=vp[j-1]+vp[j];
                vs[n-j]=vs[j];
            }
            vs[n]=1;
            v.push_back(vs);
        }
        return v;
    }
};