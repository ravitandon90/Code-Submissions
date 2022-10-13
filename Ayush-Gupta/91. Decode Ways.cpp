class Solution {
public:
    int dp[101];
    int fun(string &s, int ind){
        if(ind == s.size()) return 1;
        if(s[ind] == '0') return 0;
        if(ind == s.size()-1) return 1;
        if(dp[ind] != -1) return dp[ind];
        int ans = fun(s, ind+1);
        if(stoi(s.substr(ind, 2)) <= 26) ans += fun(s, ind+2);
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return fun(s,0);
    }
};