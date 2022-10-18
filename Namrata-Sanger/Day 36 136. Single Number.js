/*
Day 36
136. Single Number
Link: https://leetcode.com/problems/single-number/submissions/
Level: Easy
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    for(let i = 1;i<nums.length;i++){
        nums[i] = nums[i-1] ^ nums[i];
    }
    return nums[nums.length - 1];
};
