class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        int m=s1.length(), n=s2.length();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0] && (s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=dp[0][i-1] && (s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[j-1]==s3[i+j-1]){
                    dp[i][j]=dp[i][j]|dp[i][j-1];
                }
                if(s2[i-1]==s3[i+j-1]){
                    dp[i][j]=dp[i][j]|dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
