/**
 * Problem Link - https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
 */

class Solution {
public:
    int eggdrop(int eggs, int floors, vector<vector<int>>& dp) {
        if(floors == 0 || floors == 1) {
            return floors;
        }
        
        if(eggs == 1) {
            return floors;
        }
        
        if(dp[eggs][floors] != -1){
            return dp[eggs][floors];
        }
        
        int minComb = INT_MAX;
        for(int i = 1; i <= floors; i++) {
            int localMin = 1+max(eggdrop(eggs-1, i-1, dp), eggdrop(eggs, floors-i, dp));
            minComb = min(minComb, localMin);
        }
        
        return dp[eggs][floors] = minComb;   
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp (3, vector<int> (n+1, -1));
        
        return eggdrop(2, n, dp);
    }
};