/**
 * Problem Link - https://leetcode.com/problems/partition-equal-subset-sum/
 */

class Solution {
public:
    bool topDown(vector<int>& nums, int k, int n) {
        
        if(k == 0) return true;
        
        vector<vector<bool>> dp (n+1, vector<bool>(k+1, false));
        
        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < k+1; j++) {
                if(i == 0) dp[i][j] = false;
                
                if(j == 0) dp[i][j] = true; 
            }
        }
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < k+1; j++) {
                if(nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        return dp[n][k];
        
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        for(auto num: nums) {
            sum += num;
        }
        
        if(sum %2 != 0) {
            return false;
        }
        
        int k = sum/2;
        
        return topDown(nums, k, n);
    }   
};