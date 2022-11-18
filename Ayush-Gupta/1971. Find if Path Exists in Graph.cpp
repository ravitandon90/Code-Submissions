class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(source); vis[source]=1;
        while(q.size()) {
            int u=q.front(); q.pop();
            if(u==destination) return 1;
            for(auto x: adj[u]) {
                if(vis[x]==0) {
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        return 0;
    }
};