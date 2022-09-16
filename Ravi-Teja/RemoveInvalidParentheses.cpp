class Solution {
public:
    void dfs(int i, int n, int cntl, int cntr, int br, string &temp, string &s, unordered_set<string> &ans){
        if(i>=n){
            if(cntl==cntr && cntl+cntr==br){
                ans.insert(temp);
            }
            return;
        }
        if(cntl<cntr){
            return;
        }
        if(s[i]>='a' && s[i]<='z'){
            temp.push_back(s[i]);
            dfs(i+1, n, cntl, cntr, br, temp, s, ans);
            temp.pop_back();
        }
        else{
            temp.push_back(s[i]);
            if(s[i]=='('){
                dfs(i+1, n, cntl+1, cntr, br, temp, s, ans);
            }
            else{
                dfs(i+1, n, cntl, cntr+1, br, temp, s, ans);
            }
            temp.pop_back();
            dfs(i+1, n, cntl, cntr, br, temp, s, ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int cnt=0, l=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                l++;
            }
            else if(s[i]==')' && l>0){
                l--;
                cnt+=2;
            }
        }
        int val=0;
        unordered_set<string> ans;
        string temp="";
        dfs(0, s.length(), 0, 0, cnt, temp, s, ans);
        if(ans.size()==0){
            return {""};
        }
        vector<string> res;
        for(auto x: ans){
            res.push_back(x);
        }
        return res;
    }
};