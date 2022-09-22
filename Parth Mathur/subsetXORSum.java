class Solution {
    int subset(int[] arr , int dig,int n,int sum){
        if(dig == n)
        {
            return sum;
        }
        int l = subset(arr,dig+1,n,arr[dig]^sum);
        int r = subset(arr,dig+1,n,sum);
        return l+r;
    }
    public int subsetXORSum(int[] nums)
    {
        return subset(nums,0,nums.length,0);
    }
}
