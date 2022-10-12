class Solution {
    public boolean canPartition(int[] nums) { 
           int sum = 0;
        int n = nums.length;
        
        for(int num : nums) sum+=num;
        
        if(sum%2!=0) return false;
        
        sum /= 2;
        int target = sum;
        boolean dp[][] = new boolean[n+1][target+1];
        /*for(int j=0;j<=target;j++)
        {
           if(nums[0] == j)
           dp[0][j] = true;
           else
           dp[0][j] = false;
        }
         for(int i=0;i<=n;i++)
        {
            dp[i][0] = true; 
        }*/
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(i == 0 || j==0)
                   dp[i][j] = false;
                 else if(nums[i-1] > j)     // if curr sum value is greater than the current element value then just skip(take previous value)
                    dp[i][j] = dp[i-1][j];
                else if(nums[i-1]==j)  // we got required sum
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
}
}