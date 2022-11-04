class Solution {
public:
    bool isVowel(char x) {
        x = tolower(x);
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    string reverseVowels(string s) {
        int start = 0;
        int end  = s.size() - 1;
        
        while (start < end) {
            while (start < s.size() && !isVowel(s[start])) {
                start++;
            }
            while (end >= 0 && !isVowel(s[end])) {
                end--;
            }
            if (start < end) {
                swap(s[start++], s[end--]);
            }
        }
        
        return s;
    }
};