/**
 * Problem Link - https://leetcode.com/problems/all-paths-from-source-to-target/
 */

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, vector<int>& path, int vertex, int target) {
        path.push_back(vertex);        
        
        if(vertex == target) {
            ans.push_back(path);
        } else {
             for (auto node: graph[vertex]) {
                dfs(graph, path, node, target);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int target = graph.size()-1;
        
        vector <int> path;
        dfs(graph, path, 0, target);
        
        return ans;
    }
};