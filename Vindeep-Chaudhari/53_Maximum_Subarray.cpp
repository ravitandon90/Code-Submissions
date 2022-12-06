/**
 * Problem Link - https://leetcode.com/problems/maximum-subarray/
 */

// Kadane's 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        long long int maxSoFar = INT_MIN, maxEndHere = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            maxEndHere += nums[i];
            
            if(maxEndHere > maxSoFar) {
                maxSoFar = maxEndHere;
            }
            
            if(maxEndHere < 0) {
                maxEndHere = 0;
            }
        }
        
        return maxSoFar;
    }
};