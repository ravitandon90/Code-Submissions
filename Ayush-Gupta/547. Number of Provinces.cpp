class Dsu {
    public:
    vector<int> size, parent;
    Dsu(int n) {
        size.resize(n+1, 1); parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int find(int root) {
        if(root==parent[root]) return root;
        else return parent[root]=find(parent[root]);
    }
    void unionBySize(int a, int b) {
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(size[a]<size[b]) {
            parent[a]=b;
            size[b]+=size[a];
        }
        else {
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution {
    public:
    int findCircleNum(vector<vector<int>> adj) {
        int i, j, n=adj.size(), m=adj[0].size(), ans=0;
        Dsu ds(n);
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(adj[i][j]) {
                    ds.unionBySize(i, j);
                }
            }
        }
        for(i=0;i<n;i++) if(ds.parent[i]==i) ans++;
        return ans;
    }
};