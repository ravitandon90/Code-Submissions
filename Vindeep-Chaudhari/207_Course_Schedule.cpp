/**
 * Problem Link - https://leetcode.com/problems/course-schedule/
 */

// BFS Topo Sort - Cycle in directed graph

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
          queue <int> q;
          vector<int> inDegrees (numCourses, 0);

          for(int i = 0; i < numCourses; i++) {
            for (auto node : adj[i]) {
              inDegrees[node]++;
            }
          }

          for(int i = 0; i < numCourses; i++) {
            if(inDegrees[i] == 0) {
              q.push(i);
            }
          }
    
         int vertices = 0;
          while(q.empty() ==  false) {
            int popped = q.front();
            vertices++;
            q.pop();

            for(auto node: adj[popped]) {
              inDegrees[node]--;
              if(inDegrees[node] == 0) {
                q.push(node);
              }
            }
          }
        
        if(vertices == numCourses) {
            return true;
        }
        
        return false; 
    }
};