class Solution {
    public int[] countBits(int n)
    {
        int ans[] = new int[n+1];
        int memo[] = new int[n+1];
        
        for(int i=0;i<=n; i++)
        {
            ans[i] = rec(i,memo);
        }
        return ans;
    }
    
    public int rec(int i,int[] memo)
    {
        if(i==0)return 0;
        if(i==1)return 1;
        if(memo[i] != 0) return memo[i];
        
        if(i%2 == 0)
        {
            memo[i] = rec(i/2,memo);
            return memo[i];
        }
        else
        {
            memo[i] = 1+rec(i/2,memo);
            return memo[i];
        }
        
        }
    
}
