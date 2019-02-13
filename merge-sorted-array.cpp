//https://leetcode.com/problems/merge-sorted-array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy = nums1;
        int i=0, j=0, k=0;
        while(i<m || j<n){
            if(i>=m){
                nums1[k++]=nums2[j++];
            }
            else if(j>=n){
                nums1[k++]=nums1_copy[i++];
            }
            else if(nums1_copy[i]<nums2[j]){
                nums1[k++]=nums1_copy[i++];
            }
            else nums1[k++]=nums2[j++];
        }
    }
};