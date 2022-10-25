class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        // m = number of rows
        // n = number of columns
        
        // make a matrix with m rows and n columns
        // Intialize all the matrix with '1'
        vector<vector<int>> dp(m, vector<int>(n,1));
        
        
        // No need to traverse in first row i.e. in 'i=0'
        // bcoz we want all the values of that row = 1
        // which we already did, bcoz of Intializing
        for(int i=1; i<m; i++) {
            
            // No need to traverse in first column i.e. in 'j=0'
            // bcoz we want all the values of that column = 1
            // which we already did, bcoz of Intializing
            for(int j=1; j<n; j++) {
                
                // we can go to dp[1][4] from dp[0][4] and from dp[1][3]
                // bcoz "The robot can only move 
                // either down or right at any point in time"
                // dp[1][4] = dp[0][4] + dp[1][3]
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // Return bottom-right corner of matrix
        return dp[m-1][n-1]; 
    }
};
