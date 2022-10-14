class Solution {
public:
    int f(int ind, int sum, int x, vector<int> &a, unordered_map<string, int> &dp) {
        if(ind == -1) return sum == x ? 1 : 0;
        string key = to_string(ind)+"*"+to_string(sum);
        if(dp.find(key) != dp.end()) return dp[key];
        int plus = f(ind - 1, sum + a[ind], x, a, dp);
        int minus = f(ind - 1, sum - a[ind], x, a, dp);
        return dp[key] = plus + minus;
    }
    int findTargetSumWays(vector<int>& a, int x) {
        int n = a.size(), sum = 0;
        unordered_map<string, int> dp;
        return f(n-1, sum, x, a, dp);
    }
};