class Solution {
public:
    
    int dp[3][1001];
    
    int fun(int egg, int floor) {
        
        if(floor==1 || floor==0) {
            return floor;
        }
        
        if(egg==1) {
            return floor;
        }
            
        if(dp[egg][floor]!=-1) {
            return dp[egg][floor];
        }
        
        int res;
        int mini = INT_MAX;
        
        for(int x=1; x<=floor; x++) {
            res = max(fun(egg-1, x-1), fun(egg, floor-x));
            mini = min(res, mini);
        }
        
        return dp[egg][floor] = mini+1;
    }
    
    int twoEggDrop(int n) {
        
        memset(dp, -1, sizeof(dp));
        return fun(2, n);
    }
};
