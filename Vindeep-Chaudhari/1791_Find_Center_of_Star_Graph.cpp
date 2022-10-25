/**
 * Problem Link - https://leetcode.com/problems/find-center-of-star-graph/
 */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> inDegrees (edges.size() + 2, 0);
        
        for(int i = 0; i < edges.size(); i++) {
            inDegrees[edges[i][0]]++;
            inDegrees[edges[i][1]]++;
        }

        for(int i = 1; i < inDegrees.size(); i++) {
            if(inDegrees[i] == edges.size()) {
                return i;
            }
        }
        
        return 0;
    }
};