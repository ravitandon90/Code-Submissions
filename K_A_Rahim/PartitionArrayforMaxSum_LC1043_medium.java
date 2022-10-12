class Solution { //7.53
    public int maxSumAfterPartitioning(int[] arr, int k) {
      return maxSumAfterPartitioningHelper(arr,k);
   
    }
    private int maxSumAfterPartitioningHelper(int[] nums,int limit)
    {
       int dp[] = new int[nums.length+1];
        dp[nums.length] = 0;
        for(int index = nums.length-1;index>=0;index--)
        {
        int max = Integer.MIN_VALUE;;
        int  maxVal = 0;
        int maxSum = Integer.MIN_VALUE;
        for(int i=index;i<Math.min(index+limit,nums.length);i++)
        {
          max = Math.max(max,nums[i]);
          maxVal = max * (i-index+1);
          maxVal = maxVal + dp[i+1];
          maxSum = Math.max(maxSum,maxVal);
        }
         dp[index] = maxSum;
        }
        return dp[0];
    }
}