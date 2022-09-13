class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int n, vector<int> &temp, vector<int> &nums){
        if(n<0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[n]);
        dfs(n-1, temp, nums);
        temp.pop_back();
        dfs(n-1, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> temp;
        dfs(nums.size()-1, temp, nums);
        return ans;
    }
};