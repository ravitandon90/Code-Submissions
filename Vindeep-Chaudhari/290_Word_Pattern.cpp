/**
 * Problem Link - https://leetcode.com/problems/word-pattern/
 */

class Solution {
public:
    vector<string> splitString(string s) {
        
        vector<string> ans;
        
        string delimiter = " ";
        
        int start = 0, end = -delimiter.size();

        do {
            start = end + delimiter.size();
            end = s.find(delimiter, start);
            ans.push_back(s.substr(start, end - start));
        } while (end != -1);
                          
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mp1;
        unordered_map<char, string> mp2;
        
        vector<string> strs = splitString(s);
        
        if(pattern.length() != strs.size()) return false;
        
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            
            if(mp1.find(str) == mp1.end()) {
                mp1[str] = pattern[i];
            } else if (mp1[str] != pattern[i]) {
                return false;
            }
            
            if(mp2.find(pattern[i]) == mp2.end()) {
                mp2[pattern[i]] = str;
            } else if(mp2[pattern[i]] != str) {
                return false;
            }
        }
        
        return true;
    }
};