class Solution {
public:
    int dp[201][10001];
    bool helper(int n, vector<int> &nums, int sum){
        if(sum==0){
            return true;
        }
        if(n<0 || sum<0){
            return false;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(helper(n-1, nums, sum-nums[n])){
            return dp[n][sum]=true;
        }
        return dp[n][sum]=helper(n-1, nums, sum);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int totalSum=0;
        for(auto x: nums){
            totalSum+=x;
        }
        if(totalSum & 1){
            return false;
        }
        return helper(nums.size()-1, nums, totalSum/2);
    }
};
