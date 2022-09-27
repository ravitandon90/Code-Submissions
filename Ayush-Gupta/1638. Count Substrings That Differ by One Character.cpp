class Solution {
public:
    int countSubstrings(string s, string t) {
        int i, j, n=s.size(), m=t.size(), ans=0, miss=0, pos;
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                miss = 0;
                for(pos=0; i+pos < n && j + pos < m; pos++) {
                    if(s[i+pos] != t[j+pos] && ++miss > 1) break;
                    ans += miss;
                }
            }
        }
        return ans;
    }
};