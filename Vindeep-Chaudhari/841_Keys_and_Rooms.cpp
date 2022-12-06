/**
 * Problem Link - https://leetcode.com/problems/keys-and-rooms/
 */

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for(int i = 0; i < rooms[node].size(); i++) {
            int neighbourNode = rooms[node][i];
            if(!visited[neighbourNode]) {
                dfs(rooms, visited, neighbourNode);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited (rooms.size(), false);
        
        dfs(rooms, visited, 0);
        
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == false) return false;
        }
        
        return true;
    }
};