class Solution {
public:

    // Code 2:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int maxProfit = 0;
        int mini = INT_MAX;

        for(int i=0; i<prices.size()-1; i++) {
            mini = min(prices[i], mini);
            if(prices[i] < prices[i+1]) profit = prices[i+1] - mini;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }

    /*
    // Code 1:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int currentProfit = 0;
        int minPrice = INT_MAX;
        
        for(int i=0; i<prices.size(); i++) {
            
            minPrice = min(minPrice, prices[i]);
            
            currentProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currentProfit);
            
        }
        return maxProfit;
    }
    */
};
