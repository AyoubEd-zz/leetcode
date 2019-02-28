/* https://leetcode.com/problems/1-bit-and-2-bit-characters
 * Solution: Increment pointer and see where it stops, if it stops at the last element than it is considered as one character otherwise it would have been skipped.
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            i += bits[i] + 1;
        }
        return i == bits.size()-1;
    }
};
