class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(auto i: arr) {
            mp[i]++;
        }
        set<int> s;
        for(const auto& [k, v]: mp) {
            if(!s.insert(v).second) {
                return false;
            }
        }
        return true;
    }
};