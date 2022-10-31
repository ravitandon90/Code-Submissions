/**
 * Problem Link - https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/submissions/
 */

// DFS

class Solution {
public:
    vector<int> ans;
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        
        for(int i = 0; i < adj[node].size(); i++) {
            if(!visited[adj[node][i]]) {
                visited[adj[node][i]] = true;
                dfs(adj, visited, adj[node][i]);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n);
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool> visited (n, false);
        
        for(int i = 0; i < n; i++) { 
            if(!visited[i]) {
                dfs(adj, visited, i);
            }
        }
        
        for(int i = 0; i < n; i++) { 
            if(visited[i] == false) {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};


// InDegrees

class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> inDegrees (n);
        vector<bool> visited (n, false);
        
        
        for(int i = 0; i < edges.size(); i++) {
            inDegrees[edges[i][1]]++;
            visited[edges[i][0]] = true;
            visited[edges[i][1]] = true;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) { 
            if(!visited[i] || inDegrees[i] == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};