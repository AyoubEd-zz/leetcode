/* https://leetcode.com/problems/valid-mountain-array
 * ps: always check index before condition
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return 0;
        int i = 1, a = 0, b = 0;
        while(i<A.size() && A[i]>A[i-1]){
            if(a==0) a++;
            i++;
        }
        i--;
        while(i<A.size()-1 && A[i]>A[i+1]){
            if(b==0) b++;
            i++;
        }
        return (i==A.size()-1)?a*b:0;
    }
};
