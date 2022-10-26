class Solution {
public:
    vector<string> ans;
    void backtrack(int remainingClosed, int remainingOpen, string& curr) {
        if(0 == remainingClosed) {
            ans.push_back(curr);
            return;
        }
        if(remainingClosed - remainingOpen) {
            curr += ')';
            backtrack(remainingClosed - 1, remainingOpen, curr);
            curr.pop_back();
        }
        if(remainingOpen) {
            curr += '(';
            backtrack(remainingClosed, remainingOpen - 1, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(n, n, curr);
        return ans;
    }
};