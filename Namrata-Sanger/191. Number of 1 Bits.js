/*
Day 33
191. Number of 1 Bits
Link: https://leetcode.com/problems/number-of-1-bits/
Level: Easy
*/

/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let count = 0;
    do{
        if(n%2 == 1){
            ++count;
        }
    }while((n = Math.floor(n/2)) != 0 );
    return count;
};
