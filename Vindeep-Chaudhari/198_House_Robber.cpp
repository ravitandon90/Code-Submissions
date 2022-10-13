/**
 * Problem Link - https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp (nums.size(), 0);
        
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(nums[0]+nums[2], nums[1]);
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        for(int i = 2; i < nums.size(); i++) {
            if(i-3 < 0) {
                dp[i] = nums[i] + dp[i-2];
            } else {
                dp[i] = nums[i] + max(dp[i-2], dp[i-3]);
            }
            
        }
        
        return *max_element(dp.begin(), dp.end());
        

    }
};