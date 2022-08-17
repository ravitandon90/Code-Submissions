/**
 * Problem Link - https://leetcode.com/problems/sum-of-all-subset-xor-totals/
 */
class Solution {
public:
    void getSubsetsAndSum(vector<int>& nums, int& XorSum, int i, int xorTill) {
        if(i == nums.size()) return;

         XorSum += xorTill^nums[i];

        getSubsetsAndSum(nums, XorSum, i+1, xorTill^nums[i]);
        getSubsetsAndSum(nums, XorSum, i+1, xorTill);
    }
    int subsetXORSum(vector<int>& nums) {

        int XorSum = 0;
        getSubsetsAndSum(nums, XorSum, 0, 0);

        return XorSum;
    }
};