class Solution {
    int dp[] = new int[46];
    public int climbStairs(int n) { 
        Arrays.fill(dp,-1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        return helper(n);
       
    }
     private int helper(int n)
        {
           if(dp[n] != -1)
               return dp[n];
           return dp[n] = helper(n-1) + helper(n-2);
        }
}