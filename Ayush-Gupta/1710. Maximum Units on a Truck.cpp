class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& a, int x) {
        int ans = 0;
        sort(a.begin(), a.end(), comp);
        for(auto nums: a) {
            if(x <= 0) break;
            if(x >= nums[0]) ans += (nums[0] * nums[1]);
            else ans += (x * nums[1]);
            x -= nums[0];
        }
        return ans;
    }
};