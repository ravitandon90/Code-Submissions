class Solution {
public:
    void helper(int source, int target, vector<int> &visit, vector<vector<int>> &graph, vector<int> temp, vector<vector<int>> &paths){
        if(source==target){
            temp.push_back(source);
            paths.push_back(temp);
            return;
        }
        visit[source]=1;
        temp.push_back(source);
        for(auto adjacentNode: graph[source]){
            if(visit[adjacentNode]==0){
                helper(adjacentNode, target, visit, graph, temp, paths);
            }
        }
        visit[source]=0;
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        int n=graph.size();
        vector<int> visit(n, 0), temp;
        helper(0, n-1, visit, graph, temp, paths);
        return paths;
    }
};
