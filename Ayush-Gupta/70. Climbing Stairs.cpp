class Solution {
public:
    int f(int n, vector<int> &dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int x = f(n-1, dp);
        int y = f(n-2, dp);
        return dp[n] = x+y;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};