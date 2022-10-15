/**
 * Problem Link - https://leetcode.com/problems/unique-paths/ 
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        dp[1][1] = 1;
        
        for(int i = 0; i < m+1; i++) {
            for(int j = 0; j < n+1; j++) {
                if(i == 1 || j == 1) {
                    dp[i][j] = 1;
                }
            }
        }
        
        for(int i = 2; i < m+1; i++) {
            for(int j = 2; j < n+1; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};