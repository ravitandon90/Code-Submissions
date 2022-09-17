class Solution {
public:
    void fun(string curr, int open, int close, int n, vector<string> &ans) {
        if(curr.size() == 2*n) {
            ans.push_back(curr);
            return;
        }
        if(open<n) fun(curr+'(', open+1, close, n, ans);
        if(close<open) fun(curr+')', open, close+1, n, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun("(" , 1, 0, n, ans);
        return ans;
    }
};