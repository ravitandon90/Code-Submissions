/**
 * Problem Link - https://leetcode.com/problems/trapping-rain-water/
 */

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax (height.size());
        vector<int> rightMax (height.size());  

        for(int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for(int i = height.size()-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            int level = min(leftMax[i], rightMax[i]);
            if(level >= height[i]) {
                ans += level - height[i];
            }
        }

        return ans;
    }
};