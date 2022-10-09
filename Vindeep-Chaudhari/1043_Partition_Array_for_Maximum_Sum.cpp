/**
 * Problem Link - https://leetcode.com/problems/partition-array-for-maximum-sum/
 */

// Memoized - TLE

class Solution {
public:
    int helper(vector<int> arr, vector<int>& dp, int index, int k) {
        if(index >= arr.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int currMax = 0;
        int sumMax = 0;
        for(int j = 0; j < k; j++) {
            int to = index+j;
            if(to >= arr.size()) {
                break;
            }
            
            currMax = max(currMax, arr[to]);
            int leftPartitionSum = currMax * (j+1);
            int rightPartitionSum = helper(arr, dp, to+1, k);
            
            sumMax = max(sumMax, leftPartitionSum + rightPartitionSum);
        }
        
        return dp[index] = sumMax;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp (arr.size(), -1);
        
        return helper(arr, dp, 0, k);
    }
};

// Tabulated

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp (arr.size()+1);
        
        for(int i = 0; i < arr.size(); i++) {
            int currMax = 0;
            for(int j = 0; j < k; j++) {
                int from = i-j;
                
                if(from < 0) {
                    continue;
                }
                
                currMax = max(currMax, arr[from]);
                int leftPSum = currMax * (j+1);
                int rightPSum = from - 1 < 0 ? 0 : dp[from-1];
                
                dp[i] = max(dp[i], leftPSum + rightPSum);
            }
        }
        
        return dp[arr.size()-1];
    }
};