/**
 * Problem Link - https://leetcode.com/problems/reverse-words-in-a-string
 */

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string curr = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(curr.length() > 0) {
                    if(ans.length() == 0) {
                        ans += curr;
                    } else {
                        string temp = curr + " " + ans;
                        ans = temp;
                    }
                    curr = "";
                }
                continue;
            } else {
                curr += s[i];
            }
        }

        if(curr.length() > 0) {
                    if(ans.length() == 0) {
                        ans += curr;
                    } else {
                        string temp = curr + " " + ans;
                        ans = temp;
                    }
                }

        return ans;
    }
};