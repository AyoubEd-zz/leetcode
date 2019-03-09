/* https://leetcode.com/problems/reverse-integer
 * Solution: take care of edge cases where it overflows for positive and negative integers
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x!=0){
            if((long long)res*10>INT_MAX || (long long)res*10<INT_MIN) return 0;
            else res=res*10 + x%10;
            x/=10;
        }
        return res;
    }
};
