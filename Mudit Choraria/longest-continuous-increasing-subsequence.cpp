class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1, ans = INT_MIN;
        for(int i = 1; i < size(nums); i++) {
            if(nums[i - 1] < nums[i]) {
                // keep increasing the count until a decreasing pair is found
                count++;
            } else {
                // reset the count when a decreasing pair is found
                ans = max(ans, count);
                count = 1;
            }
        }
        return max(ans, count);
    }
};