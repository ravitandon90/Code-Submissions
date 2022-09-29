class Solution {
public:
    int dp[101];
    int helper(int i, int n, string &s){
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        int fd=(s[i]-'0');
        if(fd>=1 && fd<=26){
            ans+=helper(i+1, n, s);
        }
        if(i+1<n && fd>=1 && (fd*10+(s[i+1]-'0')>=1) && (fd*10+(s[i+1]-'0')<=26)){
            ans+=helper(i+2, n, s);
        } 
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(0, s.length(), s); 
    }
};