class Solution {
public:
    string reverseWords(string s) {
        string ans = "", curr = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                ans += curr + ' ';
                curr = "";
            } else {
                curr = s[i] + curr;
                if(i + 1 == s.size()) {
                    ans += curr;
                }
            }
        }
        return ans;
    }
};