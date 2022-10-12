class Solution {
public:
    int dp[502];
    int helper(int i, int n, int k, vector<int> &arr, int mx, int cnt){
        if(i>=n){
            return mx*cnt;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int inc=0;
        if(cnt < k){
            inc=helper(i+1, n, k, arr, max(mx, arr[i]), cnt+1);
        }
        int exc=mx*cnt +  helper(i+1, n, k, arr, arr[i], 1);
        return dp[i]=max(inc, exc);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(1, arr.size(), k, arr, arr[0], 1);
    }
};
