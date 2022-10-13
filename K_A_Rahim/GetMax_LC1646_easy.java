class Solution {
    public int getMaximumGenerated(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int[] nums = new int[n+1];
        nums[0] = 0;
        nums[1] = 1;
        for(int i=2;i<=n;i++)
        {
            if(i % 2 == 0)
            {
                nums[i] = nums[i/2];
            }
            else
            {
                nums[i] = nums[i/2] + nums[i/2 + 1];
            }
        }
        /*if((nums.length -1) % 2 == 1)
            return nums[nums.length - 1];
        else
            return nums[nums.length - 2];*/
        int max = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++)
        {
            max = Math.max(max,nums[i]);
        }
        return max;
            
    }
}