class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        
        while(i<j) {
            
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }            
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int n = s.length();
        int cnt = 0;
        int i = 0;
        int j = n-1;
        
        while(i<j) {
            
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else if((s[i] != s[j]) && (cnt == 0)) {
                
                cnt++;                
                return (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1));
            }
            else if((s[i] != s[j]) && (cnt != 0)) {
                return false;
            }
            
        }
        return true;
    }
};
