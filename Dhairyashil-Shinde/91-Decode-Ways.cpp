class Solution {
public:
//     int numDecodings(string s) {    
//     }
    
    int numDecodings(const string& s) {
    // int numDecodings(string s) {    
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for (int i=n-1; i>=0; --i) {
        
            if (s[i] != '0') // Single digit
                dp[i] += dp[i+1];
            
            if (i+1 < n && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) 
                dp[i] += dp[i+2]; // Two digits
        }
        return dp[0];
    }
};
