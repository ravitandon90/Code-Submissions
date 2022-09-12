class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        if(a.second==b.second) return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& a) {
        unordered_map<int, int> mp;
        for(auto x: a) mp[x]++;
        vector<pair<int, int>> v;
        for(auto x: mp) v.push_back({x.first, x.second});
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for(auto x: v) {
            int val=x.second;
            while(val--) ans.push_back(x.first);
        }
        return ans;
    }
};