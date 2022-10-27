class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        vis[i] = 1;
        for(auto x: adj[i]){
            if(vis[x] == 0){
                dfs(x, adj, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int i, n = adj.size(), cnt = 0;
        vector<int> vis(n,0);
        for(i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis);
                cnt++;
            }
        }
        return (cnt == 1);
    }
};
