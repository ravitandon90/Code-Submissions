/*
Day 19:
905. Sort Array By Parity
Link: https://leetcode.com/problems/sort-array-by-parity/
Level: Easy
*/

var sortArrayByParity = function(nums) {
    return nums.sort((a,b)=>(a%2) - (b%2));
};
