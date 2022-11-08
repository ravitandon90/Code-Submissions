class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curr = 0;
        for(int i: nums) {
            curr = max(curr + i, i);
            ans = max(curr, ans);
        }
        return ans;
    }
};
