class Solution {
    public int numIdenticalPairs(int[] nums) {
        int freqCount[] = new int[101];
        int pairCount = 0;
        for(int i=0;i<nums.length;i++)
        {
            if(freqCount[nums[i]] != 0)
            {
              pairCount += freqCount[nums[i]];  
            }
            freqCount[nums[i]]++; 
        }
       return pairCount;
    }
}