class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& G, int i, vector<int>& path) {
        
        // add current node to path
        path.push_back(i);
        
        // valid path found
        if(i == size(G)-1) {
            ans.push_back(path); 
        }
        // recurse for every possible next node in path
        else {
            for(auto child : G[i]) {
                dfs(G, child, path); 
            }
        }
                
        // backtrack
        path.pop_back(); 
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, path);
        return ans;
    }
};
