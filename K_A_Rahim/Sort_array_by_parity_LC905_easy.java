class Solution { 
    public int[] sortArrayByParity(int[] nums) {
        int sorted[] = new int[nums.length];
        int destPointer = 0;
        for(int i=0;i<nums.length;i++)
        {
          if(nums[i] % 2 == 0)
          sorted[destPointer++] = nums[i];
        }
          for(int i=0;i<nums.length;i++)
        {
          if(nums[i] % 2 != 0)
          sorted[destPointer++] = nums[i];
        }
        return sorted;
    }
}