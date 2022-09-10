class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;
        bool isDecreasing = true;
        
        for(int i = 1; i < size(nums); i++) {
            if(nums[i] > nums[i - 1]) {
                isDecreasing = false;
            }
            if(nums[i] < nums[i - 1]) {
                isIncreasing = false;
            }
        }
        
        return isIncreasing || isDecreasing;
    }
};