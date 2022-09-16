/**
 * Problem Link - https://leetcode.com/problems/generate-parentheses/
 */

class Solution {
public:
    void backtrack(vector<string>& ans, string str, int open, int close, int n) {
        
        if(str.length() == n*2) {
            ans.push_back(str);
            return;
        }
        
        if(open < n) {
            str += '(';
            backtrack(ans, str, open+1, close, n);
            str.pop_back();
        }
        
        if(close < open) {
            str += ')';
            backtrack(ans, str, open, close+1, n);
            str.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        backtrack(ans, "", 0, 0 , n);
        
        return ans;
    }
};