/**
 * Problem Link - https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int destination, int node) {

        visited[node] = true;
        
        if(node == destination) {
            return true;
        }
        
        bool reach = false;
        for(int i = 0; i < adj[node].size(); i++) {
            if(!visited[adj[node][i]]) {
                reach |= dfs(adj, visited, destination, adj[node][i]);
            }
        }
        
        return reach;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj (n);
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited (n, false);
        
        return dfs(adj, visited, destination, source);
        
    }
};