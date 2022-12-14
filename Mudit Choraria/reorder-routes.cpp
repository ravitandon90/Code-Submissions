class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n + 5];
        for(auto con: connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(-con[0]);
        }
        vector<bool> vis(n + 5, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int ans = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for(auto i: adj[curr]) {
                if(!vis[abs(i)]) {
                    if(i > 0) {
                        ans++;
                    }
                    vis[abs(i)] = true;
                    q.push(abs(i));
                }
            }
        }
        return ans;
    }
};