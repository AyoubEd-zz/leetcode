/*https://leetcode.com/problems/sort-array-by-parity-ii
 * Solution: Two pointers, one on odds the other on evens
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0, j=1;
        while(i<A.size() && j<A.size()){
            if(A[i]%2==0) i+=2;
            else if(A[j]%2==1) j+=2;
            else {swap(A[i], A[j]);i+=2;j+=2;}
        }
        return A;
    }
};
