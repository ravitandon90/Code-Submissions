class Solution {
public:
    void dfs(string &temp, int cntl, int cntr, int n, vector<string> &ans){
        if(cntl==cntr && cntl==n){
            ans.push_back(temp);
            return;
        }
        if(cntl>n || cntr>n || cntl < cntr){
            return;
        }
        temp.push_back('(');
        dfs(temp, cntl+1, cntr, n, ans);
        temp.pop_back();
        temp.push_back(')');
        dfs(temp, cntl, cntr+1, n, ans);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        dfs(temp, 0, 0, n, ans);
        return ans;
    }
};