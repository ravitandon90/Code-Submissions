class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(auto x: edges) {
            mp[x[0]]++;
            mp[x[1]]++;
        }
        for(auto x: mp) {
            if(x.second == edges.size()) return x.first;
        }
        return -1;
    }
};