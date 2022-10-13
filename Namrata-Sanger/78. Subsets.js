/*
Day 26
78. Subsets
Link: https://leetcode.com/problems/subsets/
Level: Medium
*/
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let results = [[]];
    for(let i=0; i<nums.length;i++){
        let data = [];
        for(let j = 0; j<results.length; j++){
            let temp = results[j];
            temp = [...temp,nums[i]];
            data.push(temp);
        }
        results = [...results,...data];
    }
    return results;
};
