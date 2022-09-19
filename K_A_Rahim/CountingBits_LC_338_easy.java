class Solution {
    public int[] countBits(int n) {
        int count = 0;
        int[] ans = new int[n+1];
    for(int num =0;num<=n;num++)
    {
        count = 0;
       for(int i=0;i<32;i++)
       {
           if(((num >> i) & 1) > 0)
               count++;
       }
      ans[num] = count;
    }
      return ans;  
    }
}