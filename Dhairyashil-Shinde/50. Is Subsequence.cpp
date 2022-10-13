class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        if(n==0 && m==0) {
            return true;
        }
        else if(n==0 && m!=0) {
            return true;
        }
        else if(m<n) {
            return false;
        }
        
        int i=0;
        int j=0;
        while(i<n || j<m) {
            
            if(s[i]==t[j] && i>=n-1) {
                return true;
            }
            else if(s[i]!=t[j] && j>=m-1) {
                return false;
            }
            else if(s[i]==t[j]) {
                i++;
                j++;
            }
            else if(s[i]!=t[j]) {
                j++;
            }
            
        }
        return true;
    }
};
