
/*
Day 9
1480. Running Sum of 1d Array
Link: https://leetcode.com/problems/running-sum-of-1d-array/
Level:  Easy
*/


/**
 * @param {number[]} nums
 * @return {number[]}
 */
// time-complexity : O(n)
// space-complexity : O(1)
var runningSum = function(nums) {
    for(let i=1; i<nums.length;i++){
        nums[i] += nums[i-1];
    }
    return nums;
};
