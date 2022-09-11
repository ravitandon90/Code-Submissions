class Solution { 
    public boolean isMonotonic(int[] nums) {
       return checkMonotonic(nums,nums[nums.length - 1] - nums[0]);  
    }
    private boolean checkMonotonic(int[] nums, int diff)
    {
            for(int i=1;i<nums.length;i++)
            {
                if(diff > 0 && nums[i] - nums[i-1] < 0)
                return false;
                if(diff < 0 && nums[i] - nums[i-1] > 0)
                return false;
                if(diff == 0 && nums[i] != nums[i-1])
                return false;
            }
        return true;
    }
}