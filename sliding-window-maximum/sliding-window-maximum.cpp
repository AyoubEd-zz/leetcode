class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i >= k)
                res.push_back(nums[dq.front()]);
            
            if(!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        res.push_back(nums[dq.front()]);
        
        return res;
    }
};