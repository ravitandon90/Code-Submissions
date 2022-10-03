/**
 * Problem Link - https://leetcode.com/problems/house-robber-ii/
 */

class Solution {
public:
    int robHouses(vector<int> houses) {
        vector<int> dp (houses.size()+1, 0);
        
        dp[0] = houses[0];
        dp[1] = houses[1];
        
        for(int i = 2; i < houses.size(); i++) {
            if(i-3 < 0) {
                dp[i] = houses[i] + dp[i-2];
            } else {
                dp[i] = houses[i] + max(dp[i-2], dp[i-3]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2 || nums.size() == 3) return *max_element(nums.begin(), nums.end());
        
        int house1 = robHouses(vector<int> (nums.begin(), nums.end()-1));
        int house2 = robHouses(vector<int> (nums.begin()+1, nums.end()));
        
        return max(house1, house2);
        
    }
};