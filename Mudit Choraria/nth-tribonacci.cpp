class Solution {
public:
    int dp[40] = {};
    int tribonacci(int n) {
        if(n < 3) {
            return n != 0;
        }
        
        return dp[n] = dp[n] ? dp[n] : tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    }
};