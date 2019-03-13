/* https://leetcode.com/problems/image-smoother
 * Solution: iterate through Grid
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.size()==0) return {{}};
        vector<vector<int>> output(M.size(), vector<int>(M[0].size()));
        vector<vector<int>> cor = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int g,h, out, count;
        for(int i=0; i<M.size() ; i++){
            for(int j=0 ; j<M[0].size() ; j++){
                out=0, count=0;
                for(int k=0 ; k<cor.size() ; k++){
                    g = i + cor[k][0];
                    h = j + cor[k][1];
                    if(g>=0 && g<M.size() && h>=0 && h<M[0].size()){
                        out += M[g][h];
                        count++;
                    }
                }
                output[i][j] = floor((1.0*out)/count);
            }
        }
        return output;
    }
};
