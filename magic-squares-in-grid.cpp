/* https://leetcode.com/problems/magic-squares-in-grid
 * Solution: Magic grid always has 5 in the middle
*/

class Solution {
public:
    bool checkNumbers(vector<int>& nums){
        set<int> st = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(auto a:nums) st.erase(a);
        if(st.size()!=0) return 0;
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int count = 0;
        for(int i=0 ; i<grid.size() ; i++){
            if(grid.size()-i<3) break;
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[0].size()-j<3) continue;
                cout<<i<<" "<<j<<endl;
                if(grid[i+1][j+1]!=5) continue;
                vector<int> v;
                for(int k = i; k<i+3 ; k++){
                    for(int r=j ; r<j+3 ; r++){
                        v.push_back(grid[k][r]);
                    }
                }
                if(
                    checkNumbers(v)
                  && grid[i][j]+grid[i+1][j]+grid[i+2][j] == 15
                  && grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1] == 15
                  && grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2] == 15
                  
                  && grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2] == 15
                  && grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] == 15
                  && grid[i][j]+grid[i][j+1]+grid[i][j+2] == 15
                  
                  && grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] == 15
                  && grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2] == 15){
                    count++;
                }
            }
        }
        return count;
    }
};
