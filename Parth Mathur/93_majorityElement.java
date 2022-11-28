class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int rem = 0;

        for(int i=0; i<nums.length; i++)
        {
            int c = hm.containsKey(nums[i]) ? hm.get(nums[i]) : 0;
            hm.put(nums[i],c+1); 

            if(hm.get(nums[i]) > nums.length/2)
            {
                rem = nums[i];
                break;
            }
        }
    return rem;
        

    }
}
