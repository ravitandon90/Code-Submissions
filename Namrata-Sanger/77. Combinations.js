/*
Day 24
77. Combinations
Link: https://leetcode.com/problems/combinations/
Level: Medium
*/

/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
 
 
var combine = function(n, k) {
    let result = [];
    
    function backtracking(start, comb){
        if(comb.length == k){
            result.push([...comb]);
            return
        }
        for(let i = start; i<=n; i++){
            comb.push(i);
            backtracking(i+1, comb);
            comb.pop();
        }
    }
    backtracking(1,[]);
    return result;
};
