/**
 * Problem Link - https://leetcode.com/problems/container-with-most-water/
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;

        int maxArea = INT_MIN;
        while(start < end) {
            int currArea = 0;
            if(height[start] < height[end]) {
                currArea = height[start]*(end-start);
                start++;
            } else {
                currArea = height[end]*(end-start);
                end--;
            }

            maxArea = max(maxArea, currArea);
        }

        return maxArea;

    }
};