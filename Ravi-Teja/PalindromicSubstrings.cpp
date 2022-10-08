class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(), cnt=1;
        vector<vector<int>> dp(2, vector<int> (n, 0));
        dp[(n-1)%2][n-1]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<=n-1;j++){
                if(s[i]==s[j]){
                    dp[i%2][j]=(i+1>=j-1) ? 1 : (dp[(i+1)%2][j-1]);
                }
                else{
                    dp[i%2][j]=0;
                }
                cnt+=dp[i%2][j];
            }
            for(int j=0;j<n;j++){
                dp[(i+1)%2][j]=dp[i%2][j];
            }
        }
        return cnt;
    }
};
