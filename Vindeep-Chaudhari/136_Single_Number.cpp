/**
 * Problem Link - https://leetcode.com/problems/single-number/
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int num: nums) {
            ans = ans^num;
        }
        
        return ans;
    }
};