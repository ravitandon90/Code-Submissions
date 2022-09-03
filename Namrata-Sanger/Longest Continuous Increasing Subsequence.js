/*
Day 10
674. Longest Continuous Increasing Subsequence
Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
Level: Easy
*/

/**
 * @param {number[]} nums
 * @return {number}
 */

// O(n) - time complexity
var findLengthOfLCIS = function(nums) {
    let max_count = 1;
    let pointer = 0;
    for(let i=1; i<nums.length;i++){
        if(nums[i] <= nums[i-1]){
            pointer = i;      
        }
        if(max_count < (i - pointer + 1)){
            max_count = i - pointer + 1;
        }
    }
    return max_count;
};
