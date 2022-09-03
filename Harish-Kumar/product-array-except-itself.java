/* 

problem link - https://leetcode.com/problems/product-of-array-except-self/

Reference - https://leetcode.com/problems/product-of-array-except-self/discuss/2508484/JAVA-2-approaches-with-clear-code-and-comments%2Bexample

*/


class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        int[] res = new int[nums.length];
        
        
        res[0] = 1;
        for(int i  = 1 ; i < nums.length;i++){
            res[i] = res[i-1] * nums[i-1]; 
        }
        int prod = 1;
        for(int j = nums.length-2;j>=0;j--){
            prod = prod * nums[j+1];
            res[j] = res[j] * prod;
        }
        return res;
        
    }
}