/**
 * Problem Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        
        map<char, string> dial;
        
        dial['2'] = "abc";
        dial['3'] = "def";
        dial['4'] = "ghi";
        dial['5'] = "jkl";
        dial['6'] = "mno";
        dial['7'] = "pqrs";
        dial['8'] = "tuv";
        dial['9'] = "wxyz";
        
        vector <string> ans;
        ans.push_back("");
        
        for(int i = 0; i < digits.length();i++) {
            string a = dial[digits[i]];
                vector <string> temp; 
                for(int in  = 0; in < a.length(); in++) {
                    for(auto s: ans) {
                        temp.push_back( s + a[in]);
                    }
                }
                
                ans.swap(temp);
        
        }
        
        return ans;
        
        
    }
};