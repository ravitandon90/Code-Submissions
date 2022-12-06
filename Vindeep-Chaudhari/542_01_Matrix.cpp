/**
 * Problem Link - https://leetcode.com/problems/01-matrix/description/
 */

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans (mat.size(), vector<int> (mat[0].size(), 0));
        vector<vector<int>> visited (mat.size(), vector<int> (mat[0].size(), 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                } else {
                    visited[i][j] = 0;
                }
            }
        }

        while(q.empty() == false) {
            auto popped = q.front();
            q.pop();

            int i = popped.first.first;
            int j = popped.first.second;
            int dist = popped.second;

            ans[i][j] = dist;

            if(i+1 >= 0 && j >= 0 && i+1 < m && j < n && visited[i+1][j] == 0) {
                visited[i+1][j] = 1;
                q.push({{i+1, j}, dist+1});
            }

            if(i-1 >= 0 && j >= 0 && i-1 < m && j < n && visited[i-1][j] == 0) {
                visited[i-1][j] = 1;
                q.push({{i-1, j}, dist+1});
            }

            if(i >= 0 && j+1 >= 0 && i < m && j+1 < n && visited[i][j+1] == 0) {
                visited[i][j+1] = 1;
                q.push({{i, j+1}, dist+1});
            }

            if(i >= 0 && j-1 >= 0 && i < m && j-1 < n && visited[i][j-1] == 0) {
                visited[i][j-1] = 1;
                q.push({{i, j-1}, dist+1});
            }
        } 

        return ans;
    }
};  
