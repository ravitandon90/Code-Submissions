class Solution {
    bool f(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (i == s1.length() && j == s2.length() && k == s3.length()) {
            return dp[i][j] = true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s3[k] == s1[i] && s3[k] != s2[j]) {
            return dp[i][j] = f(i + 1, j, k + 1, s1, s2, s3, dp);
        } 
        else if (s3[k] == s2[j] && s3[k] != s1[i]) {
            return dp[i][j] = f(i, j+1, k+1, s1, s2, s3, dp);
        } 
        else if (s3[k] == s1[i] && s3[k] == s2[j]) {
            return dp[i][j] = f(i, j+1, k+1, s1, s2, s3, dp) || f(i + 1, j, k + 1, s1, s2, s3, dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return f(0, 0, 0, s1, s2, s3, dp);
        
    }
};
