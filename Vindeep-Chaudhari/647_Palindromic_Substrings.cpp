/**
 * Problem Link - https://leetcode.com/problems/palindromic-substrings/
 */

// Memoised

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += solve(dp, s, i, j);
            }
        }
        return count;
    }
    
    int solve(vector<vector<int>>& dp, string& s, int i, int j) {
        if (i >= j) return 1;
        if (dp[i][j] >= 0) return dp[i][j];
        return dp[i][j] = s[i] == s[j] ? solve(dp, s, i+1, j-1) : 0;
    }
};

// Tabulated

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        int count = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};

