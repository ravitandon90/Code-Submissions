class Solution {
public:
    void dijkstra(int V, vector<vector<int>> &graph, int S, vector<int> &dist)
    {
        int i,j,u,v;
        dist[S]=0;
        queue<vector<int>> q;
        q.push({0,S});
        while(q.size()){
            vector<int> vec=q.front(); q.pop();
            u=vec[1];
            for(v=0;v<=V;v++){
                if(graph[u][v]!=-1 && dist[v]>dist[u]+graph[u][v]){
                    dist[v]=dist[u]+graph[u][v];
                    q.push({dist[v],v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int V, int S) {
        int i,j,u,v,wt,maxi=-1;;
        vector<int> dist(V+1);
        for(i=0;i<=V;i++) dist[i]=INT_MAX;
        vector<vector<int>> graph(V+1, vector<int>(V+1));
        for(i=0;i<=V;i++){
            for(j=0;j<=V;j++){
                graph[i][j]=-1;
            }
        }
        for(i=0;i<times.size();i++){
            u=times[i][0]; v=times[i][1]; wt=times[i][2];
            graph[u][v]=wt;
        }
        dijkstra(V,graph,S,dist);
        for(i=1;i<=V;i++){
            if(dist[i]==INT_MAX) return -1;
            if(dist[i]!=INT_MAX) maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};