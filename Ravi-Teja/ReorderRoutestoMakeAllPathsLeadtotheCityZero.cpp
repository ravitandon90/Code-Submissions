class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,bool>> adj[n];
        for(auto connection: connections){
            adj[connection[0]].push_back({connection[1], true});
            adj[connection[1]].push_back({connection[0], false});
        }
        vector<bool> visit(n, false);
        queue<int> q;
        q.push(0);
        visit[0]=true;
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbors: adj[node]){
                if(visit[neighbors.first]==false){
                    visit[neighbors.first]=true;
                    q.push(neighbors.first);
                    if(neighbors.second==false){
                        count++;
                    }
                }
            }
        }
        return n-count-1;
    }
};
