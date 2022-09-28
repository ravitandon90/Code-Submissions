 class Solution {
     public boolean divisorGame(int N) {           
   
       boolean[] dp = new boolean[N+1];
       for(int i=1;i<=N;i++)
        {
            if(i==1) dp[i]=false;
            else if(i==2) dp[i]=true;
            else{
                for(int j=1;j*j<=i;j++)
                {
                    if(i%j==0)
                    {
                       dp[i] = !dp[i-j];
                        break;
                    }
                }    
            }  
        }
        return dp[N];
    }
}
