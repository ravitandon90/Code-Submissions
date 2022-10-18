/**
 * Problem Link - https://leetcode.com/problems/jump-game/
 */

// Dp

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<int> dp (nums.size());
        dp[nums.size()-1] = 1;
        
        for(int i = nums.size()-2; i >= 0; i--) {
            if(nums[i] == 0) {
                dp[i] = 0;
                continue;
            }
            
            int reach = i+nums[i];
            
            for(int j = i+1; j <= reach; j++) {
                if(j < nums.size() && dp[j]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[0];
    
    }
};


// Optimized

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int reach = 0;
        
        if(nums.size() == 1 && nums[0] == 0) return true;
        
        for(int i = 0; i < nums.size(); i++) {
            if(reach < i) {
                return false;
            }
            
            reach = max(reach,i+ nums[i]);
        }
        
        return true;
    
    }
};