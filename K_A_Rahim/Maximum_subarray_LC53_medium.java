class Solution {
    public int maxSubArray(int[] nums) { // 6.48
       int sum = 0;
       int maxSum = Integer.MIN_VALUE;
       for(int num : nums)
       {
         sum += num;
         maxSum = Math.max(maxSum,sum);
         if(sum <= 0)
         {
             sum = 0;
         } 
       }
       return maxSum; 
    }
}