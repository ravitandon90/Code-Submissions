class Solution {
public:
    int dp[22][40003];
    int helper(int n, vector<int> &nums, int target){
        if(n<0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp[n][target+20000]!=-1){
            return dp[n][target+20000];
        }
        return dp[n][target+20000]=helper(n-1, nums, target-nums[n]) + helper(n-1, nums, target+nums[n]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=0;
        for(auto x: nums){
            totSum+=x;
        }
        if(totSum < target || target < totSum*(-1)){
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return helper(nums.size()-1, nums, target);
    }
};
