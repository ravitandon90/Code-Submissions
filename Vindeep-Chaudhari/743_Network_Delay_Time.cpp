/**
 * Problem Link - https://leetcode.com/problems/network-delay-time/submissions/
 */


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map <int,vector<pair<int,int>>> mp;
        
        for(int i = 0; i < times.size(); i++) {
            mp[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        
        vector<int> distance (n+1, INT_MAX);
        vector<bool> visited (n+1, false);
        
        distance[k] = 0;
        visited[k] = true;
        
        queue<int> q;
        q.push(k);
        
        while(q.empty() == false) {
            int popped = q.front();
            q.pop();
            
            for(int i = 0; i < mp[popped].size(); i++) {
                int node = mp[popped][i].first;
                int dist = mp[popped][i].second;
                
                int time = distance[popped] + dist;
                
                if(distance[node] > time) {
                    distance[node] = time;
                    q.push(node);
                }
            }
        }
        
        
        int ans = INT_MIN;
        for(int i = 1; i < distance.size(); i++) {
            if(distance[i] == INT_MAX) return -1;
            
            ans = max(ans, distance[i]);
        }
        
        return ans;
    }
};