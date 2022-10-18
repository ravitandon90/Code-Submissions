class Solution {
public:    
    int Memoization(int n, vector<int>& dp) {
        if(n==0 || n==1) 
            return n;
        
        if(dp[n] != -1) 
            return dp[n];
        
        return dp[n] = Memoization(n-1, dp) + Memoization(n-2, dp);
    }
    
    int fib(int n) {
        vector<int> dp(n+1,-1); //Size = n+1, Intialized to -1
        
        return Memoization(n,dp);
    }
};
