class Solution {
public:
    int count;
    void helper(int node, vector<int> adj[], vector<int> &visit){
        visit[node]=1;
        count++;
        for(auto x: adj[node]){
            if(visit[x]==0){
                helper(x, adj, visit);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            adj[i]=rooms[i];
        }
        count=0;
        vector<int> visit(n, 0);
        helper(0, adj, visit);
        return count==n;
    }
};
