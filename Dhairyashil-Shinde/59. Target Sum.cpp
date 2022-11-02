class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the value of 'sum+target' is odd 
        // then we can't divide that sum in two subsets
        if( (sum+target) % 2 != 0 ) return 0;
        
        int newTargetForSubset1 = (sum+target)/2;
        if(newTargetForSubset1 < 0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(newTargetForSubset1+1, 0) );
        
        for(int i=0; i<n+1; i++) 
            dp[i][0] = 1; // Intially keep the values 1
        
        for(int i=1; i<n+1; i++) {
            for(int j=0; j<newTargetForSubset1+1; j++) {
                
                if(nums[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                
            }
        }
        return dp[n][newTargetForSubset1];
    }
};
