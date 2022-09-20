class Solution {
    public int singleNumber(int[] nums) {
        int rem = 0;
        for(int i=0; i<nums.length;i++)
        {
            rem = rem ^ nums[i];
        }
        return rem;
    }
}
