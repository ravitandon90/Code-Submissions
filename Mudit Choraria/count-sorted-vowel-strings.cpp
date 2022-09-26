class Solution {
public:
    int countVowels(int id, int n, vector<vector<int>>& dp) {
        if(n == 0) {
            return 1;
        }
        if(id == 0) {
            return 0;
        }
        if(dp[id][n] != -1) {
            return dp[id][n];
        }
        return dp[id][n] = countVowels(id - 1, n, dp) + countVowels(id, n - 1, dp);
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6, vector<int>(n + 1, -1));
        return countVowels(5, n, dp);
    }
};