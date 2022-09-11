class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else if(maxProfit < prices[i] - minPrice) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};