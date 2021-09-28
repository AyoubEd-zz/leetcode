class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        for(const auto& in: intervals) {
            if(merged.empty() || merged.back()[1] < in[0])
                merged.push_back(in);
            else
                merged.back()[1] = max(in[1], merged.back()[1]);
        }
        
        return merged;
    }
};