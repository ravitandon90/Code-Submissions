/**
 * Problem Link -https://leetcode.com/problems/target-sum/
 */

// Memoized

class Solution {
public:
    int recurse(vector<int>& nums, int sum, int target, int index, vector<vector<int>>& dp, int totalSum) {
        if(target == sum && index == nums.size()) {
            return 1;
        }

        if(index == nums.size()) {
            return 0;
        }
        
        if(dp[index][sum+totalSum] != INT_MIN) {
            return dp[index][sum+totalSum];
        }
        
        dp[index][sum+totalSum] = recurse(nums, sum+nums[index], target, index+1, dp, totalSum) + recurse(nums, sum-nums[index], target, index+1, dp, totalSum);
        
        return dp[index][sum+totalSum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto num : nums) {
            totalSum += num;
        }
        
        vector<vector<int>> dp (nums.size(), vector<int> ((2*totalSum)+1, INT_MIN));
        return recurse(nums, 0, target, 0, dp, totalSum);
    }
};

// 2D Dp

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto num : nums) {
            totalSum += num;
        }
        
        vector<vector<int>> dp (nums.size(), vector<int> ((2*totalSum)+1, 0));
        
        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;
        
        for(int i = 1; i < nums.size(); i++) {
            for(int j = -totalSum; j <= totalSum; j++) {
                if(dp[i-1][j+totalSum] > 0) {
                    dp[i][j + nums[i] + totalSum] += dp[i-1][j + totalSum];
                    dp[i][j - nums[i] + totalSum] += dp[i-1][j + totalSum];
                } 
            }
        }
        
        if(abs(target) > totalSum) return 0;
        
        return dp[nums.size()-1][target + totalSum];
    }
};

