/*
Day 16
189. Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Level: Medium
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */

function reverse(nums,low,high){
        while(low < high){
            let temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
}
    
var rotate = function(nums, k) {    
        while(k>nums.length){
            k -= nums.length;
        }
        let half = nums.length - k;
        reverse(nums,half,nums.length-1);
        reverse(nums,0,half-1);
        reverse(nums,0,nums.length - 1);
    
};
