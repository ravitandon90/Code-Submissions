/**
 * Problem Link - https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 */

class Solution {
public:
    int minEdges = 0;
    void dfs (vector<vector<int>>& adj, vector<bool>& visited, int node, int& count) {
        visited[node] = true;
        
        int change = 0;
        for(int i = 0; i < adj[node].size(); i++) {
            if(!visited[abs(adj[node][i])]) {
                if(adj[node][i] > 0) {
                    count++;
                }
                dfs(adj, visited, abs(adj[node][i]), count);
            }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj (n);
        
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        
        vector<bool> visited (n);
        int count = 0;
        dfs(adj, visited, 0, count);
        
        return count;
    }
};

