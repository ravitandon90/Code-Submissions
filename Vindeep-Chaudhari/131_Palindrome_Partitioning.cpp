/**
 * Problem Link - https://leetcode.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        if(s.empty()) return ans;
        
        vector<string> path;
        dfs(0, s, path);
        
        return ans;
    }
    
    void dfs(int index, string& s, vector<string>& path) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};