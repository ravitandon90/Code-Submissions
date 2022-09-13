/**
 * Problem Link - https://leetcode.com/problems/monotonic-array/
 */

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1 | nums.size() == 2) return true;
        
        int nature = nums[1] - nums[0];
        for(int i = 1; i < nums.size()-1; i++) {
            int diff = nums[i+1] - nums[i];
            
            if(nature == 0) {
                nature = diff;
            } else {
                if(diff < 0 && nature > 0) return false;
                else if (diff > 0 && nature < 0) return false;
            }
        }
        
        return true;
    }
};