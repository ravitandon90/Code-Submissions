class Solution {
public:
    int f(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return 0;
            i++; j--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int i, j, n=s.size(), ans=0;
        for(i=0;i<n;i++) {
            for(j=i;j<n;j++) {
                ans += f(s, i, j);
            }
        }
        return ans;
    }
};