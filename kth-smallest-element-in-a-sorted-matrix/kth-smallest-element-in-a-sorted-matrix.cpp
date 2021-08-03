

class Solution {
public:
    struct comp{
  bool operator()(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
    return p1.first > p2.first;
  }
    };
    
    int kthSmallest(vector<vector<int>>& lists, int k) {
        int res;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;

        for(int i = 0; i < lists.size(); i++) {
          pq.push({lists[i][0], {i, 0}});
        }

        for(int i = 0; i < k; i++) {
          auto p = pq.top(); pq.pop();
          res = p.first;

          if(p.second.second + 1 < lists[p.second.first].size()) pq.push({lists[p.second.first][p.second.second + 1], {p.second.first, p.second.second + 1}});
        }

        return res;
    }
};