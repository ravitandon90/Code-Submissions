class Solution {
public:
    int minReorder(int n, vector<vector<int>>& a) {
        int ans=0;
        vector<vector<int>> adj(n);
        set<pair<int, int>> st;
        for(auto x: a) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            st.insert({x[0], x[1]});
        }
        vector<int> vis(n, 0);
        queue<int> q; 
        q.push(0); vis[0]=1;
        while(q.size()) {
            int u=q.front(); q.pop();
            for(auto x: adj[u]) {
                if(vis[x]==0) {
                    vis[x]=1;
                    q.push(x);
                    if(st.find({u, x}) != st.end()) ans++;
                }
            }
        }
        return ans;
    }
};