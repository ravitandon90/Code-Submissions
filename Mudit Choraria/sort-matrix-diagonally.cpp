class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = size(mat);
        int n = size(mat[0]);
        
        unordered_map<int, priority_queue<int>> count;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                count[i - j].push(-mat[i][j]);
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mat[i][j] = -count[i - j].top(), count[i - j].pop();
            }
        }
        
        return mat;
    }
};
