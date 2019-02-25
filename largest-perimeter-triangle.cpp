/* https://leetcode.com/problems/largest-perimeter-triangle
 * Solution: By sorting the triangle, we take check all consecutive elements. Why consecutive? Beause if take the last element as a constant and we search for the  other two, if there's a       * couple j, k that verifies the inequality A[i]<A[k]+A[j] where k<i && j<i then i-1 and i-2 also verify the inequality.
*/
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size()<3) return 0;
        sort(A.begin(), A.end());
        for (int i = A.size() - 3; i >= 0; i--){
            if (A[i] + A[i+1] > A[i+2]){
                return A[i] + A[i+1] + A[i+2];
            }
        }
        return 0;
    }
};
