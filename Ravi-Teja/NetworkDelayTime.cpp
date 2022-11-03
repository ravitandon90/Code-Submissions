class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1, INT_MAX);
        int sz=times.size();
        for(int i=0;i<sz;i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        queue<int> q;
        q.push(k);
        dist[k]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x: adj[node]){
                if(dist[node] + x.second < dist[x.first]){
                    q.push(x.first);
                    dist[x.first]=dist[node]+x.second;
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            mx=max(mx, dist[i]);
        }
        return mx;
    }
};
