/**
 * Problem Link - https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        
        int maxLCIS = 0;
        int localLCIS = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                localLCIS++;
            } else {
                localLCIS = 1;
            }
            
            maxLCIS = max(maxLCIS, localLCIS);
        }
        
        return maxLCIS;
    }
};

// Time complexity - O(N)
// Space complexity - O(1)