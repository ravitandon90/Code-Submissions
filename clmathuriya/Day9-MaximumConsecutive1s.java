class Solution {
    //485. Max Consecutive Ones : https://leetcode.com/problems/max-consecutive-ones/
    
    public int findMaxConsecutiveOnes(int[] nums) {
        int max=0;
        int temp=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                if(i-1>=0 && nums[i-1]==1){
                    temp++;
                }else{
                    temp=1;
                }
                
                if(temp>max){
                    max=temp;
                }
            }
        }
        return max;
    }
}
