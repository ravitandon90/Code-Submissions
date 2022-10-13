class Solution {
    public int singleNumber(int[] nums) {
       /* java 1.7
        int ans = 0;
       for(int number : nums) 
       {
           ans ^= number;
       }
        return ans;*/
       // java 1.8
        return Arrays.stream(nums).reduce(0,(elem1,elem2) -> (elem1 ^ elem2));
    }
}