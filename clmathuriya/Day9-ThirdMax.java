class Solution {
    //414. Third Maximum Number : https://leetcode.com/problems/third-maximum-number/
    public int thirdMax(int[] nums) {
        long max=Long.MIN_VALUE;
        long secondMax=Long.MIN_VALUE;
        long thirdMax=Long.MIN_VALUE;
        boolean foundThird=false;
        
        for(int i=0;i<nums.length;i++){
            if(nums[i]>max){
                if(thirdMax<secondMax){
                    thirdMax=secondMax;
                    foundThird=true;
                    
                }
                secondMax=secondMax<max?max:secondMax;
                max=nums[i];
            }else if(nums[i]>secondMax && (nums[i]!=max)){
                if(thirdMax<secondMax){
                    thirdMax=secondMax;
                    foundThird=true;
                    
                }
                secondMax=nums[i];
            } else if(nums[i]>=thirdMax && nums[i]!=max && (nums[i]!=secondMax)){
                thirdMax=nums[i];
                foundThird=true;
                
            }
            
            
        }
        if(foundThird){
            return (int)thirdMax;
        }
          return (int)max;
        
        
        
    }
}
