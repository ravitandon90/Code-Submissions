class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) {
            return 0;
        }
        
        vector<int> buy(k + 1, INT_MAX);
        vector<int> sell(k + 1, 0);
        
        for(auto& price: prices) {
            for(int i = 1; i <= k; i++) {
                buy[i] = min(buy[i], price - sell[i - 1]);
                sell[i] = max(sell[i], price - buy[i]);
            }
        }
        return sell.back();
    }
};