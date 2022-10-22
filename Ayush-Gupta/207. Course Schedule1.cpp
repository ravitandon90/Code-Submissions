class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> in(n, 0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(auto x: a) {
            in[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        for(int i=0;i<n;i++) {
            if(in[i]==0) {
                q.push(i);
            }
        }
        while(q.size()) {
            int u=q.front(); q.pop();
            for(auto x: adj[u]) {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
        }
        for(auto x: in) {
            if(x != 0) return 0;
        }
        return 1;
    }
};