/* 
https://leetcode.com/problems/counting-bits/

x/2 = y

then  = no of set bits in x - no of set bits in y = 1

if number is odd , then no of set bits  = arr[1+ x/2 ](where x is the number)
if number is even , then no of set bits  = arr [x/2] (where x is the number)
*/
public int[] countBits(int n) {
    int dp[] = new int[n+1];
    dp[0] = 0;
    if(n == 0) return dp;
    dp[1] = 1;
    if(n == 1) return dp;
    for(int i = 2 ; i <= n ; i++){
        if(i % 2 == 0) dp[i] = dp[i/2];
        else dp[i] = dp[i/2] +1;
    }
    return dp;
}