
struct comp{
  bool operator()(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) {
    return p1.first > p2.first;
  }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& lists) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;
        int maxsofar = 0;
        for(int i = 0; i < lists.size(); i++) {
          pq.push({lists[i][0], {i, 0}});
          maxsofar = max(maxsofar, lists[i][0]);
        }

        pair<int, int> result = {0, numeric_limits<int>::max()};

        while(pq.size() == lists.size()) {
          auto p = pq.top(); pq.pop();

          if(maxsofar - p.first < result.second - result.first) {
            result = {p.first, maxsofar};
          }

          if(p.second.second + 1 < lists[p.second.first].size()) { 
            pq.push({lists[p.second.first][p.second.second + 1], {p.second.first, p.second.second + 1}});
            maxsofar = max(maxsofar, lists[p.second.first][p.second.second + 1]);
          }
        }

        return {result.first, result.second};   
    }
};