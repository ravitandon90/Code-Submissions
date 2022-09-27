class Solution {
public:
    int countSubstrings(string s, string t) {
       int M = s.size(), N = t.size(), ans = 0, left[101][101] = {}, right[101][101] = {};
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                left[i + 1][j + 1] = s[i] == t[j] ? left[i][j] + 1 : 0;
            }
        }
        
        for(int i = M - 1; i >= 0; i--) {
            for(int j = N - 1; j >= 0; j--) {
                right[i][j] = s[i] == t[j] ? right[i + 1][j + 1] + 1 : 0;
            }
        }
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(s[i] != t[j]) {
                    ans += (1 + left[i][j]) * (1 + right[i + 1][j + 1]);
                }
            }
        }
        return ans;
    }
};