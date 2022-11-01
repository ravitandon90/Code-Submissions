class Solution {
public:
    void dfs(int src, int dst, vector<vector<int>> &adj, vector<vector<int>> &ans, vector<int> temp) {
        temp.push_back(src);
        if(src == dst) {
            ans.push_back(temp);
            return;
        }
        for(auto x: adj[src]) dfs(x, dst, adj, ans, temp);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=adj.size();
        if(n==0) return ans;
        dfs(0, n-1, adj, ans, temp);
        return ans;
    }
};