class Solution {
private:
    bool makePalindrome(string s) {
        int change = 0;
        int l = 0;
        int r = s.size() - 1;

    while (l < r) {
        if (s[l++] != s[r--] && ++change > 2) {
            return false;
        }
    }
};