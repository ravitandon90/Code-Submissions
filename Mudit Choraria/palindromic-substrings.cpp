class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size();
        for(int i = 0; i < s.size(); i++) {
            // odd length substrings
            int j = i - 1, k = i + 1;
            while(j >= 0 && k < s.size()) {
                if(s[j] == s[k]) {
                    ans++;
                    j--;
                    k++;
                }
                else {
                    break;
                }
            }
            // even length substrings
            j = i, k = i + 1;
            while(j >= 0 && k < s.size()) {
                if(s[j] == s[k]) {
                    ans++;
                    j--;
                    k++;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};