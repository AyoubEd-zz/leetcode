/* https://leetcode.com/problems/min-cost-climbing-stairs
 * Solution: DP from th bottom up
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f1=0, f0=0, mem;
        for(int i=cost.size()-1 ; i>=0 ; i--){
            mem = f0;
            f0 = cost[i]+min(f0, f1);
            f1 = mem;
        }
        return min(f0, f1);
    }
};
