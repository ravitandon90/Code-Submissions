class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length(), n=t.length();
        if(m > n){
            return false;
        }
        int i=0, j=0;
        while(j<n){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==m;
    }
};
