class Solution {
public:
    bool cycle(int node, vector<int> adj[], vector<int> &vis){
        if(vis[node]==1){
            return true;
        }
        if(vis[node]==0){
            vis[node]=1;
            for(auto x: adj[node]){
                if(cycle(x, adj, vis)){
                    return true;
                }
            }
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        bool ans=true;
        vector<int> vis(numCourses, 0), explored(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(cycle(i, adj, vis)){
                return false;
            }
        }
        return true;
    }
};
