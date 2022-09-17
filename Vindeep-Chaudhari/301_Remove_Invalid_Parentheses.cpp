/**
 * Problem Link - https://leetcode.com/problems/remove-invalid-parentheses/
 */

class Solution {
public:
    bool isValidP(string s) {
        int sum = 0;
        for(char &c : s) {
            if(c == '(') ++sum;
            else if(c == ')') --sum;
            if(sum < 0) return false;
        }
        return sum == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int open = 0, close = 0;
        for(char &c : s) {
            open += c == '(';
            if (open == 0) {
                close += c == ')';
            } else {
                open -= c == ')';
            }
        }
        vector<string> ans;
        dfs(s, 0, open, close, ans);
        return ans;
    }
    void dfs(string s, int beg, int open, int close, vector<string> &ans) {
        if(open == 0 && close == 0) {
            if(isValidP(s))
                ans.push_back(s);
        } else {
            for(int i = beg; i < s.size(); ++i) {
                string tmp = s;
                if(open > 0 && tmp[i] == '(') {
                    if(i == beg || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, open - 1, close, ans);
                    }
                }
                if(close > 0 && tmp[i] == ')') {
                    if(i == beg || tmp[i] != tmp[i - 1]) {
                        tmp.erase(i, 1);
                        dfs(tmp, i, open, close - 1, ans);
                    }
                }
            }
        }
    }
};
