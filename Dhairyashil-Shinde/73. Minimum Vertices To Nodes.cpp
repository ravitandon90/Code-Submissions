class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections) {
    
        vector<pair<int,int>> graph[n];
        for(auto i: connections) {
            graph[i[0]].push_back({1, i[1]});
            graph[i[1]].push_back({0, i[0]});
        }
        
        vector<bool> vis(n, 0);
        int ans = 0; 
		    queue<int> q; 
		    q.push(0); vis[0]=1;
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            for(auto [w,v]: graph[node]) {
                if(vis[v]) 
                    continue;
                
                ans += w; 
				        q.push(v); vis[v] = 1;
            }
        }
        return ans;
    }
};
