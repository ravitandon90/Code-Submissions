class myComparator {
  public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) {
      if(p1.first == p2.first) {
          return p1.second < p2.second;
      }
      return p1.first > p2.first;
    }
};
class Solution {
public: 
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(string s: words) {
            mp[s]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComparator> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans(k);
        while(!pq.empty()) {
            ans[--k] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};