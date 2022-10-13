class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int n, vector<int> &nums, set<vector<int>> &result, vector<int> &temp, vector<int> &vis){
        if(temp.size()==n){
            result.insert(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                temp.push_back(nums[i]);
                vis[i]=1;
                dfs(n, nums, result, temp, vis);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        int n=nums.size();
        vector<int> vis(n, 0), temp;
        set<vector<int>> result;
        dfs(n, nums, result, temp, vis);
        for(auto x: result){
            ans.push_back(x);
        }
        return ans;
    }
};