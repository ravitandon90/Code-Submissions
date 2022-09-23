class Solution {
    int ans = 0;
    // WAY 1 using...backtracking TC = O(n * 2^n) SC due to recursion = O(log n) )
    public int subsetXORSum(int[] nums) {
       generateSubsets(0,nums,0);
        return ans;
    }
       /*
       //WAY 2 .....USING BIT MASKING  TC = O(n * 2^n) SC  = O(1)
       public int subsetXORSum(int[] nums) {
        int sum=0;
        for(int i=1;i<(1<<nums.length);i++){
            int xor=0;
            for(int j=0;j<nums.length;j++){
                if((i&(1<<j))!=0){
                    xor=xor^nums[j];
                    
                }
            }
            sum+=xor;
        }
        return sum;
    }
    private void generateSubsets(int index,int[] nums,int xorVal)
    {
        /*if(index == nums.length)
        {*/
            ans += xorVal;
           /* return;
        }*/
        for(int i=index;i<nums.length;i++)
        {
          xorVal = xorVal ^ nums[i];
          generateSubsets(i+1,nums,xorVal);
          xorVal = xorVal ^ nums[i];
        }
    }
}