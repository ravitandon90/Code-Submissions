class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto c: s) {
            mp[c]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) { 
           return mp[a] == mp[b] ? b > a : mp[a] > mp[b];
        });
        return s;
    }
};