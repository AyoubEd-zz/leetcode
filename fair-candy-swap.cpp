/* https://leetcode.com/problems/fair-candy-swap
 * Solution: Rather than Going through all the couples which will be O(n^2), we store elements of B in a bitset. Then we go through A looking for an element that would verify
 * the following equation iB = iA + (sumB-sumA)/2;
 * ps: using bitet is faster than using set and saves space.
*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bitset<200002> bf;

        int sumA = 0, sumB = 0;
        for(auto n: A) {
            sumA += n;
        }
        for(auto n: B) {
            sumB += n;
            bf.set(n);
        }

        for(int i:A){
            int det = i+((sumB-sumA)/2);
            if(det>0 && bf.test(det)) return {i, (sumB-sumA)/2+i};
        }
        return {};
    }
};
