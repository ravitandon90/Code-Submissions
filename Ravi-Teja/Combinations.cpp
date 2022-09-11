class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, int n, int k, vector<int> &temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i+1;j<=n;j++){
            temp.push_back(j);
            dfs(j, n, k-1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> temp;
        dfs(0, n, k, temp);
        return ans;
    }
};