/**
 * Problem Link - https://leetcode.com/problems/ones-and-zeroes/
 */

// Memoized

class Solution {
public:
    
    pair<int, int> getOnesZeros(string str) {
        int ones = 0, zeros = 0;
        for(auto i: str) {
            if(i == '0') zeros++;
            else ones++;
        }
        
        return {zeros, ones};
    }
    
    int recursive(vector<vector<vector<int>>>& dp, vector<string>& strs, int l, int m, int n) {
        
        if(l < 0) {
            return 0;
        }
        
        auto count = getOnesZeros(strs[l]);
        
        if(dp[l][m][n] != -1 ) {
            return dp[l][m][n];
        }
        
        if(count.first > m || count.second > n) {
            return dp[l][m][n] = recursive(dp, strs, l-1, m, n);
        }
            
        return dp[l][m][n] = max(
            1+recursive(dp, strs,l-1,m-count.first,n-count.second),
            recursive(dp, strs,l-1,m,n)
        );
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<vector<int>>> dp (strs.size()+1, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        
        
        int maxSub = recursive(dp, strs, strs.size()-1, m, n);
        return maxSub;
        
    }
};

// Tabulated

class Solution {
public:
    
    pair<int, int> getOnesZeros(string str) {
        int ones = 0, zeros = 0;
        for(auto i: str) {
            if(i == '0') zeros++;
            else ones++;
        }
        
        return {zeros, ones};
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp (m+1, vector<int> (n+1));
        
        for(int i = 0; i < strs.size(); i++) {
            
            auto count = getOnesZeros(strs[i]);
            
            for(int j = m; j >= count.first; j--) {
                for(int k = n; k >= count.second; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j-count.first][k-count.second]);
                }
            }
        }
        
        return dp[m][n];
        
    }
};