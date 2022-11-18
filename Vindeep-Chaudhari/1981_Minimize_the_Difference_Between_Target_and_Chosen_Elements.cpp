/**
 * Problem Link - https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
 */

class Solution {
public:
    int minDiff = INT_MAX;
    int recurse(vector<vector<int>>& mat, int target, int rowIndex, int colIndex, int sum, vector<vector<int>>& dp) {
        if(rowIndex >= mat.size()) {
            return abs(target-sum);
        }
        
        if(dp[sum][rowIndex] != -1) {
            return dp[sum][rowIndex];
        }
        
        int minDiff = INT_MAX;
        for(int i = 0; i < mat[0].size(); i++) {
            minDiff = min(minDiff, recurse(mat, target, rowIndex+1, i, sum+mat[rowIndex][i], dp));
            if(minDiff == 0) break;
        }
        
        return dp[sum][rowIndex] = minDiff;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        vector<vector<int>> dp (5001, vector<int> (mat.size(), -1));
        
        return recurse(mat, target, 0, 0, 0, dp);
    }
};