class Solution {
public:
    int f(int i, int j, int n, int m, vector<vector<int>> &dp) {
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int x = f(i+1, j, n, m, dp);
        int y = f(i, j+1, n, m, dp);
        return dp[i][j] = x+y;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(0, 0, n, m, dp);
    }
};