class Solution {
public:
    
    unordered_map<string, int> map;
    int dp[305][305];
    
    bool solve(string &s, int n, int start) {
    
        if(start==n) return true;
        if(dp[start][n]!=-1) return dp[start][n];
        
        for(int i=start; i<n; ++i){
        
            string str = s.substr(start,i-start+1);
            
            if(map.find(str)!=map.end()) {
                if(solve(s,n,i+1)) return dp[start][n] = true;
            }
        }
        return dp[start][n] = false;
    }
    
    bool wordBreak(string &s, vector<string>& wordDict) {
    
        memset(dp,-1,sizeof(dp));
        for(auto &word : wordDict) map[word]++;
        int n=s.size();
        return solve(s,n,0);
    }
};
