/* https://leetcode.com/problems/fibonacci-number
 *  Solution: Array to memorize
*/
class Solution {
public:
    int fib(int N) {
        if(N < 2) return N;
        int mem[N+1];
        mem[0]=0; mem[1]=1;
        for(int i=2 ; i<=N ; i++){
            mem[i] = mem[i-1] + mem[i-2];
        }
        return mem[N];
    }
};
