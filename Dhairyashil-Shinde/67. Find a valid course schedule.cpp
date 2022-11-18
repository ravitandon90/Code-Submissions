class Solution {
public:
    
    bool isCycle(vector<vector<int>>& graph,vector<int> &colors,int i) {
    
        if (colors[i] == 1) return true;
        
        if (colors[i] == 0) {
        
            colors[i] = 1;
            for (auto neighbor : graph[i]) {
                if (isCycle(graph, colors, neighbor)) return true;
            }
        }
        
        colors[i] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> colors(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        // build graph
        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!colors[i]) {
                if (isCycle(graph, colors, i)) return false;
            }
            
        }
        return true;
    }
};
