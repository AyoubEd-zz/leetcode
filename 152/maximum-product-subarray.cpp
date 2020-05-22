class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long cp = 1;
        int max_neg = INT_MIN;
        int mx = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(i==0) cp = nums[i];
            else cp *= nums[i];

            if(cp > mx) {
                mx = cp;
            } else if(cp<0 && (cp/max_neg) > mx) {
                mx = cp/max_neg;
            }
            
            if(cp<0 && cp > max_neg) {
                max_neg = cp;
            }
            if(cp==0) {
                cp = 1;
                max_neg = INT_MIN;
            }
        }
        
        return mx;
    }
};
