class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        for(const int& i : nums2)
            nums1.push_back(i);
        
        std::sort(std::begin(nums1), std::end(nums1));
        
        if(nums1.size() % 2 == 0)
        {
            int middle_id = (nums1.size() - 1) / 2;
            double answ = double(nums1[middle_id] + nums1[middle_id+1]) / 2;
            
            return answ;
        }
        else
        {
            int middle_id = nums1.size() / 2;
            return nums1[middle_id];
        }
    }
};