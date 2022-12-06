class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int ansI = -1, ansT = INT_MAX;
        long pref = 0, suff = accumulate(nums.begin(), nums.end(), 0L);
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            suff -= nums[i];
            int curr = pref / (i + 1);
            curr -= (i == n - 1) ? 0 : suff / (n - i - 1);
            curr = abs(curr);
            if(curr < ansT) {
                ansT = curr;
                ansI = i;
            }
        }
        return ansI;
    }
};