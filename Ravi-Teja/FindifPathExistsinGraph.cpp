class Solution {
public:
    int find(int node, vector<int> &parent){
        if(parent[node]==-1){
            return node;
        }
        return parent[node]=find(parent[node], parent);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n+1, -1);
        for(int i=0;i<edges.size();i++){
            int u=find(edges[i][0], parent);
            int v=find(edges[i][1], parent);
            if(u!=v){
                parent[u]=v;
            }
        }
        return find(source, parent)==find(destination, parent);
    }
};
