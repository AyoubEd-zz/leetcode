/* https://leetcode.com/problems/reshape-the-matrix
 * Solution:  variable count res[count/c][count%c]
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r*c != (nums.size())*(nums[0].size())) return nums;
        vector<vector<int>> v(r, vector<int>(c));
        int a = 0, b = 0;
        for(int i=0; i<r ; i++){
            for(int j=0 ; j<c ; j++){
                v[i][j] = nums[a][b];
                if(b == nums[0].size()-1){
                    b = 0;
                    a = (a+1)%(nums.size());
                }else b = (b+1)%(nums[0].size());
            }
        }
        return v;
    }
};
/*
 * class Solution {
 *public:
 *    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
 *        if(r*c != (nums.size())*(nums[0].size())) return nums;
 *        vector<vector<int>> v(r, vector<int>(c));
 *        int count = 0;
 *        for(int i=0; i<nums.size() ; i++){
 *            for(int j=0 ; j<nums[0].size() ; j++){
 *                v[count/c][count%c] = nums[i][j];
 *                count++;
 *            }
 *        }
 *        return v;
 *    }
 *};
*/
