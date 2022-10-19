/**
 * Problem Link - https://leetcode.com/problems/number-of-provinces/
 */

// DFS

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for(int i = 0; i < isConnected[node].size(); i++) {
            if(!visited[i] && i != node && isConnected[node][i]) {
                dfs(isConnected, visited, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited (isConnected.size(), false);
        
        int noOfProvinces = 0;
        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, i);
                noOfProvinces++;
            }
        }
        
        return noOfProvinces;
    }
};
