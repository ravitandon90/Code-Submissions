/*
Day 35
190. Reverse Bits
Link: https://leetcode.com/problems/reverse-bits/
Level: Easy
*/

/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    let arr = n.toString(2).split('').reverse();
    return arr.push.apply( arr, new Array(32 - arr.length).fill(0) ) && parseInt(arr.join(''), 2);
};
