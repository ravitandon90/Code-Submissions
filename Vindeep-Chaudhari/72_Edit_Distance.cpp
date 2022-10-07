/**
 * Problem Link - https://leetcode.com/problems/edit-distance/
*/

// Memoized

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1, vector<int> (word2.size()+1, -1));
        return helper(word1, word2, word1.size(), word2.size(), dp);
    }
    
    int helper(string word1, string word2, int m, int n, vector<vector<int>>& dp) {
        if(m == 0) return dp[m][n] = n;
        if(n == 0) return dp[m][n] = m;
        
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        
        if(word1[m-1] == word2[n-1]) {
            return dp[m][n] = helper(word1, word2, m-1, n-1, dp);
        } 
            
        int insertStr = helper(word1, word2, m, n-1, dp);
        int replaceStr = helper(word1, word2, m-1, n-1, dp);
        int deleteStr = helper(word1, word2, m-1, n, dp);

        return dp[m][n] =  1 + min({ insertStr, replaceStr, deleteStr });
    }
};


// Tabulated

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1, vector<int> (word2.size()+1, -1));
        
        for(int i = 0;  i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        
        for(int j = 0;  j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int insert = dp[i][j-1];
                    int replace = dp[i-1][j-1];
                    int deleteS = dp[i-1][j];
                    
                    dp[i][j] = 1 + min({ insert, replace, deleteS });
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
    
};