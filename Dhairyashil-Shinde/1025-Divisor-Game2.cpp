class Solution {
public:
    /*
    bool divisorGame(int N) {
        return N%2==0;
    }
    */
        
    int dp[1001];
    
    int recursionDp(int N) {
        
        if(N==1) 
            return 0;
        
        if(dp[N] !=-1 ) {
            return dp[N];
        }
        else {

           for(int i = 1; i*i <= N; i++) {
               
               if(N%i == 0) {
                   
                   if(recursionDp(N-i) == 0) 
                       return dp[N] = 1;
                   
                   if((i != 1) && recursionDp(N-(N/i)) == 0)
                       return dp[N] = 1;
               }  
            }
            return dp[N] = 0;
        }
    }
        
    bool divisorGame(int N) {
        memset(dp, -1, sizeof dp );
        return recursionDp(N);
    }
    
};
