class Solution {
  
 static boolean dp[] = new boolean[1001];
    public static boolean solve(int n, char person){
      if(n==1) return false;
      if(dp[n] != false) return dp[n];
      if(dp[n] == false){
        
      for(int i =1; i<n; i++){
        if(n%i == 0){
            if(person=='A'){
              boolean b = solve(n-i, 'B');
              if(!b) dp[n]= true;
            }else{
              boolean b = solve(n-i, 'A');
              if(!b) dp[n]=  true;
            }
        }
        
      }
      }
      return dp[n];
      
    }
    public boolean divisorGame(int n) {
 
      return solve(n,'A');
    }
}
