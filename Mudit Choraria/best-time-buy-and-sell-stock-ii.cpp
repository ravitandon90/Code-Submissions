class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i - 1]) {
                maxProf += prices[i] - prices[i - 1];
            }
        }
        return maxProf;
    }
};