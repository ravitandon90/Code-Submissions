class Solution {
public:
    bool f(int ind, vector<int> &a, int sum, vector<vector<int>> &dp) {
        if(ind == -1) return sum == 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool notTake = f(ind-1, a, sum, dp);
        bool take = 0;
        if(sum >= a[ind]) take = f(ind-1, a, sum-a[ind], dp);
        return dp[ind][sum] = take | notTake;
    }
    bool canPartition(vector<int>& a) {
        int sum=0, n=a.size();
        for(auto x: a) sum+=x;
        if(sum&1) return 0;
        sum>>=1;
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return f(n-1, a, sum, dp);
    }
};