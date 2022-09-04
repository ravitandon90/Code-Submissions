class Solution {
public:
    // Time Complexity - O(n)
    // Space Complexity - O(1)
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) 
          nums[i]+=nums[i-1];
        return nums;
    }
};
