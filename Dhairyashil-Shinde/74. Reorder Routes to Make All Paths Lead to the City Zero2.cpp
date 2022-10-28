class Solution {
public:
  
    // DFS
    map<pair<int,int>, bool> m;   //map to store the edges are there in connections
    int cnt = 0;                  // number of edges changed = number of edges away from 0
    
    void dfs(int v, vector<int> adj[], vector<bool> &vis) {
        
        vis[v] = true;
        for(auto u: adj[v]) {
            if(vis[u] == false) {
                if(m[{v, u}] == true) cnt++;
                dfs(u, adj, vis);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];        //adjacency list for directed graph
        vector<bool> vis(n, false);  //to mark visited cities
        
        for(auto i: connections) {  //make an undirected graph using given connections
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            m[{i[0], i[1]}] = true;    
        }
        
        dfs(0, adj, vis);  //start from capital city 0
        return cnt;
    }
    
};
