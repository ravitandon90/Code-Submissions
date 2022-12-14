class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;  
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0 && j + 1 < n) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                } else if(j == n - 1 && j - 1 >= 0) {
                    matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                } else {
                    matrix[i][j] += min(min(matrix[i - 1][j], matrix[i - 1][j - 1]), matrix[i - 1][j + 1]);
                }
            }
        }
        for(auto i: matrix[m - 1]) {
            ans = min(ans, i);
        }
        return ans;
    }
};