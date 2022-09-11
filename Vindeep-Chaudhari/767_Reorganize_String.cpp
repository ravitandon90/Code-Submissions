/**
 * Problem Link - https://leetcode.com/problems/reorganize-string/
 */

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        priority_queue <pair<int,char>> pq;
        
        int maxF = 0;
        for(auto i : s) {
            mp[i]++;
            maxF = max(maxF, mp[i]);
        }
        
        if(maxF > s.length()/2 + 1) return "";
        
        string ans = "";
        
        for(auto m : mp) {
            pq.push({m.second, m.first});
        }
        
        while(pq.size() > 1) {
            auto popped1 = pq.top();
            pq.pop();
            
            auto popped2 = pq.top();
            pq.pop();
            
            ans += popped1.second;
            ans += popped2.second;
            
            popped1.first--;
            popped2.first--;
            
            if(popped1.first > 0) {
                pq.push(popped1);
            }
            
            if(popped2.first > 0) {
                pq.push(popped2);
            }
        }
        
        if(pq.empty() == false) {
            if(pq.top().first > 1) {
                return "";
            } else {
                ans += pq.top().second;
            }
        }
        
        return ans;
    }
};