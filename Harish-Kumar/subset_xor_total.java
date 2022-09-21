/* 
https://leetcode.com/problems/sum-of-all-subset-xor-totals/
*/

class Solution {
    public int subsetXORSum(int[] nums) {
        return recur(nums, 0, 0);
    }

    public int recur(int nums[], int xor, int ind) {
        if (ind == nums.length) {
            return xor;
        }

        int withCurrentNumber = recur(nums, nums[ind] ^ xor, ind + 1);
        int withoutCurrentNumber = recur(nums, xor, ind + 1);

        return withCurrentNumber + withoutCurrentNumber;
    }
}