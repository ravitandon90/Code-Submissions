class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mini=1e9, ans=0;
        for(auto x: a) {
            mini=min(mini, x);
            ans=max(ans, x-mini);
        }
        return ans;
    }
};