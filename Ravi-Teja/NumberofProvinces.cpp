class Solution {
public:
    int findParent(int node, vector<int> &parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node], parent);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int countNodes=isConnected.size();
        vector<int> parent(countNodes);
        for(int i=0;i<countNodes;i++){
            parent[i]=i;
        }
        int totalGroups=countNodes;
        for(int i=0;i<countNodes;i++){
            for(int j=i+1;j<countNodes;j++){
                if(isConnected[i][j]==1){
                    int i_parent=findParent(i, parent);
                    int j_parent=findParent(j, parent);
                    parent[i_parent]=j_parent;
                }
            }
        }
        for(int i=0;i<countNodes;i++){
            if(parent[i]!=i){
                totalGroups--;
            }
        }
        return totalGroups;
    }
};
