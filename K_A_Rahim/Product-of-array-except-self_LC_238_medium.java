class Solution {
    public int[] productExceptSelf(int[] nums) {
       /* TC = O(n)
          SC = O(n)
       int[] prefixM = new int[nums.length];
        int[] suffixM = new int[nums.length];
        prefixM[0] = nums[0];
        for(int i=1;i<nums.length;i++)
        {
          prefixM[i] = prefixM[i-1] * nums[i]; 
        }
         suffixM[nums.length-1] = nums[nums.length-1];
        for(int i=nums.length-2;i>=0;i--)
        {
          suffixM[i] = suffixM[i+1] * nums[i]; 
        }
        int ans[] = new int[nums.length];
        ans[0] = suffixM[1];
        ans[nums.length - 1] = prefixM[nums.length - 2];
        for(int i=1;i<nums.length-1;i++)
        {
          ans[i] =  prefixM[i-1] * suffixM[i+1];
        }
        return ans;*/
       // ==============================
        //way 2
        // tc O(n) sc O(1)
        int ans[] = new int[nums.length];
          ans[nums.length -1] = nums[nums.length -1];
        for(int i=nums.length - 2;i>=0;i--)
        {
          ans[i] = ans[i+1] * nums[i]; 
        }
        int productFromLeft = 1;
        for(int i=0;i<nums.length-1;i++)
        {
          ans[i] = productFromLeft * ans[i+1];
          productFromLeft = productFromLeft * nums[i];
        }
        ans[nums.length - 1] = productFromLeft;
        return ans;
    }
}