/* https://leetcode.com/problems/shortest-unsorted-continuous-subarray
 * Solution: Find right and left slope, find min and max in that interval and determine their correct position in the array.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j && nums[i]<=nums[i+1]) i++;
        while(i<j && nums[j]>=nums[j-1]) j--;
        if(i==j) return 0;
        int mn=INT_MAX, mx=INT_MIN;
        for(int l=i ; l<=j ; l++){
            mn=min(mn, nums[l]);
            mx=max(mx, nums[l]);
        }
        int ii=0, jj=nums.size()-1;
        while(ii<i && nums[ii]<=mn) ii++;
        while(jj>j && nums[jj]>=mx) jj--;
        return (ii==jj)? 0 : jj-ii+1;
    }
};
