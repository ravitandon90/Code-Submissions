class Solution {
public:
    string reverseWords(string s) {
        string ans = "", curr = "";
        int start = 0, end = s.size() - 1;
        for(int i = start; s[i] == ' '; start = ++i);
        for(int i = end; s[i] == ' '; end = --i);
        for(int i = start; i <= end; i++) {
            if(s[i] == ' ' && curr != "") {
                ans = ' ' + curr + ans;
                curr = "";
            } else if(s[i] != ' ') {
                curr += s[i];
                if(i == end) {
                    ans = curr + ans;
                }
            }
        }
        return ans;
    }
};