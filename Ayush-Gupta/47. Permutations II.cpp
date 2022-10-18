class Solution {
public:
    void fun(vector<int> nums, int i, int j, vector<vector<int>> &ans) {
        if(i==j) {
            ans.push_back(nums);
            return;
        }
        for(int k=i;k<=j;k++) {
            if(i!=k && nums[i]==nums[k]) continue;
            swap(nums[i], nums[k]);
            fun(nums, i+1, j, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        fun(nums, 0, nums.size()-1, ans);
        return ans;
    }
};