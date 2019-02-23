/*https://leetcode.com/problems/sort-array-by-parity
 * Solution: Two Pointer and swapping like QuickSort
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1, a, b;
        while(i<j){
            a = (A[i]%2!=0);
            b = (A[j]%2==0);
            if(a==0 && b==0){i++;j--;}
            else if(a==1 && b==1){
                swap(A[i], A[j]);
                i++;j--;
            }else if(a==0 && b==1) i++;
            else j--;
        }
        return A;
    }
};
