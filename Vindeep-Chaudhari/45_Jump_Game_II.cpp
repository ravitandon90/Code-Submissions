/**
 * Problem Link - https://leetcode.com/problems/jump-game-ii/
 */

class Solution {
public:
    
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if(index == nums.size()-1) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        
        int reach = index + nums[index];
        
        int minimum = INT_MAX-1;
        for(int i = index+1; i <= reach; i++) {
            if(i < nums.size()) {
                minimum = min(minimum, 1+solve(nums, i, dp));
            }
        }
        
        return dp[index] = minimum;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        return solve(nums, 0, dp);
    }
};

// Tabulated

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        
        dp[nums.size()-1] = 0;
        
        for(int i = nums.size()-2; i >= 0; i--) {
            int reach = i + nums[i];
            int minimum = INT_MAX-1;
            for(int j = i+1; j <= reach; j++) {
                if(j < nums.size()) {
                   minimum = min(minimum, 1+dp[j]); 
                }
            }
            
            dp[i] = minimum;
        }
        
        return dp[0];
    }
};