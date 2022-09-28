class Solution { 
    // O(n) and sc = O(1)
    public int countVowelStrings(int n) {
        int[] dp = new int[] {0, 1, 1, 1, 1, 1};
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 5; ++k)
                dp[k] += dp[k - 1];
        return dp[5];
    }
    
}