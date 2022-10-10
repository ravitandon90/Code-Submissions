class Solution {
public:
    int f(int ind, int k, vector<int> &a, int n, vector<int> &dp) {
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int maxAns = 0, len = 0, maxi = -1e9, sum;
        for(int j=ind; j < min(n, ind + k); j++) {
            len++;
            maxi = max(maxi, a[j]);
            sum = (len * maxi) + f(j + 1, k, a, n, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n=a.size();
        vector<int> dp(n+1, -1);
        return f(0, k, a, n, dp);
    }
};