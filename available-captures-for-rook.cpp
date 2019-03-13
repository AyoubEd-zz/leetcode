/* https://leetcode.com/problems/available-captures-for-rook
 * Solution: cool function to avoid repetition
 */

class Solution {
public:
    int loop(vector<vector<char>>& board, int x, int y, int px, int py){
        while(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]!='B'){
            if(board[x][y]=='p') return 1;
            x+=px, y+=py;
        }
        return 0;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i=0 ; i<board.size() ; i++)
            for(int j=0 ; j<board[0].size() ; j++)
                if(board[i][j]=='R') return loop(board, i, j, 0, 1)+loop(board, i, j, 0 , -1)+loop(board, i, j, -1, 0)+loop(board, i, j, 1, 0);
        return 0;
    }
};
