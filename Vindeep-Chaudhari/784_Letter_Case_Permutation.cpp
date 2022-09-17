/**
 * Problem Link - https://leetcode.com/problems/letter-case-permutation/
 */

class Solution {
public:
    vector<string> res;
    void preparePermutation(string s, int index, string& ans) {
                
        if(ans.length() == s.length()) {
            res.push_back(ans);
        }
        
        if(index >= s.length()) return;
        
        if(isdigit(s[index])) {
            ans.push_back(s[index]);
            preparePermutation(s, index+1, ans);
            ans.pop_back();
        } else {
            
            ans.push_back(toupper(s[index]));
            preparePermutation(s, index+1, ans);
            ans.pop_back();
            
            ans.push_back(tolower(s[index]));
            preparePermutation(s, index+1, ans);
            ans.pop_back();
            
        }
    }
    vector<string> letterCasePermutation(string s) {
        string a = "";
        preparePermutation(s, 0, a);
        
        return res;
    }
};