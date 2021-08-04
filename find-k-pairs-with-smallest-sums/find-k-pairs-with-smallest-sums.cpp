struct comp{
  bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first + p1.second < p2.first + p2.second;
  }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            for(int j = 0; j < min((int)nums2.size(), k); j++) {
                if(pq.size() < k) {
                    pq.push({nums1[i], nums2[j]});
                } else {
                    auto p = pq.top();
                    if(nums1[i] + nums2[j] < p.first + p.second) {
                        pq.pop();
                        pq.push({nums1[i], nums2[j]});
                    }
                }
            }
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty()) {
            result.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        
        return result;
    }
};