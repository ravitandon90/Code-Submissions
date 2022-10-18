/**
 * Problem Link - https://leetcode.com/problems/counting-bits/
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp (n+1, 0);
        
        if(n == 0) return dp;
        
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 0) {
                dp[i] = dp[i/2];
            } else {
                dp[i] = dp[i/2] + 1;
            }
        }
        
        return dp;
    }
};