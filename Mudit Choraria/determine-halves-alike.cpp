class Solution {
public:
    bool isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' 
            || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
    }
    bool halvesAreAlike(string s) {
        int ans = 0, l = 0, r = s.size() - 1;
        while(l < r) {
            if(isVowel(s[l++])) {
                ans++;
            }
            if(isVowel(s[r--])) {
                ans--;
            }
        }
        return ans == 0;
    }
};