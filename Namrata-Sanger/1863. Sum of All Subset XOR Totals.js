/*
Day 37
1863. Sum of All Subset XOR Totals
Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/submissions/
Level: Easy 
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) {
    let output=[];
    backtrack();
    return output.reduce((a,b)=>a+b);
    function backtrack(start = 0, arr=[nums[0]]){
       output.push([...arr].reduce((a,b)=>a^b,0));
       for(let i=start; i<nums.length; i++){
            arr.push(nums[i]);
            backtrack(i+1, arr);
            arr.pop();
       }
    }
};
