class Solution {
public:
    
    int partition(int i, int k, vector<int>&arr, vector<int>&dp) {
        
        int n = arr.size();
        
        if(i == n) return 0; //base case
        
        if(dp[i] != -1) return dp[i];
        
        int length = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
        for(int j = i; j < min(n, i + k); j++) {
        
            length++; 
            maxi = max(maxi, arr[j]); 
            
            int currSum = length * maxi + partition(j + 1, k, arr, dp);
            maxAns = max(maxAns, currSum);
        }
        
        return dp[i] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>dp(n + 1, -1);
        
        int ans = partition(0, k, arr, dp);
        
        return ans;
    }
    
};
