class Solution {
    public int twoEggDrop(int floors) {
        int eggs = 2;
        int dp[][] = new int[eggs+1][floors+1];
        int c =0;
        
        for(int i=0; i <= floors; i++){
            dp[1][i] = i;
        }
        
        for(int f = 1; f <=floors; f++){
            dp[2][f] = Integer.MAX_VALUE;
                for(int k = 1; k <=f ; k++){
                    c = 1 + Math.max(dp[1][k-1], dp[2][f-k]); //the egg breaks on current floor or the egg dosen't break on the current floor. Take the worst case
                    if(c < dp[2][f])
                        dp[2][f] = c;
                }
            }
        return dp[eggs][floors];        
    }
}
