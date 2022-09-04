/**
 * Problem Link - https://leetcode.com/problems/interleaving-string/
 */

// First 

class Solution {
public:
    bool interleaving(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>>& memo) {
        
        if(i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        
        if(j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }
        
        if(memo[i][j] != -1) {
            return memo[i][j] ? true : false;
        }
        
        bool res = false;
        
        if(i < s1.length() && s1[i] == s3[k]) {
            res |= interleaving(s1, i+1, s2, j, s3, k+1, memo);
        }
        
        if(j < s2.length() && s2[j] == s3[k]) {
            res |= interleaving(s1, i, s2, j+1, s3, k+1, memo);
        }
        
        return memo[i][j] = res ? 1 : 0;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        
        vector<vector<int>> memo (s1.length(), vector<int> (s2.length(), -1));
        
        return interleaving(s1, 0, s2, 0, s3, 0, memo);
    }
};

// Second

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length() != s3.length()) return false;
        
        vector<vector<bool>> dp (s1.length()+1, vector<bool>(s2.length()+1, false));
        
        dp[0][0] = true;

        for(int j = 1; j<=s2.length(); j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1]==s3[j-1];
        }

        for(int i = 1; i<=s1.length(); i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1]==s3[i-1];
        }
        
        for(int i = 1; i <= s1.length(); i++) {
            for(int j = 1; j <= s2.length(); j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return dp[s1.length()][s2.length()];
    }
};