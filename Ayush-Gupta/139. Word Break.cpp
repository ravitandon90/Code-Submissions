class Solution {
public:
    unordered_map<string, int> dp;
    int solve(string s, vector<string> &b) {
        int n = s.size();
        if(n == 0) return 1;
        if(dp[s] != 0) return dp[s];
        for(int i=1; i<=n; i++) {
            int f = 0;
            string ss = s.substr(0, i);
            for(int j=0; j<b.size(); j++) {
                if(ss == b[j]) {
                    f = 1; break;
                }
            }
            if(f == 1 && solve(s.substr(i, n-1), b) == 1) return dp[s] = 1;
        }
        return dp[s] = -1;
    }
    bool wordBreak(string s, vector<string>& b) {
        int x = solve(s,b);
        return (x == 1) ? (1) : (0);
    }
};




