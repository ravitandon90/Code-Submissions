class Solution {
    //674. Longest Continuous Increasing Subsequence : https://leetcode.com/problems/longest-continuous-increasing-subsequence/ 
    
    public int findLengthOfLCIS(int[] nums) {
        int answer=1;
        int temp=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]>nums[i-1]){
                temp++;
            }else{
                if(temp>answer){
                    answer=temp;
                }
                temp=1;
            }
        }
        if(temp>answer){
                    answer=temp;
                }
        return answer;
        
    }
}
