//https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex+1);
        r[0]=1;
        for(int i=1; i<r.size() ; i++){
            for(int j=0; j<=i/2 ; j++){
                r[j]=r[i-j]=(long) r[j]* (long)i/(i-j);
            }
        }
        return r;
    }
};

// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<vector<int>> v = {{1}, {1, 1}};
//         if(rowIndex==0 || rowIndex==1) return v[rowIndex];
        
//         for(int i=2;i<=rowIndex;i++){
//             vector<int> vp(i+1);
//             vp[0]=1; vp[i]=1;
//             for(int j=1; j<=(i+1)/2; j++){
//                 vp[j]=v[i-1][j-1]+v[i-1][j];
//                 vp[i-j]=vp[j];
//             }
//             v.push_back(vp);
//         }
//         return v[rowIndex];
//     }   
// };