class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(const auto& in: intervals) {
            if(!pq.empty() && pq.top() <= in[0])
                pq.pop();
            
            pq.push(in[1]);
        }
        
        return pq.size();
    }
};