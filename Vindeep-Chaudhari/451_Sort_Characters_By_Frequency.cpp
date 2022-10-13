/**
 * Problem Link - https://leetcode.com/problems/sort-characters-by-frequency/
 */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        
        priority_queue <pair<int, char>> pq;
        
        for(auto m : mp) {
            pq.push({m.second, m.first});
        }
        
        string ans = "";
        while(pq.size() != 0) {
            auto popped = pq.top();
            pq.pop();
            
            while(popped.first > 0) {
                ans += popped.second;
                
                popped.first--;
            }
        }
        
        return ans;
    }
};
