/*
Day 25
47. Permutations II
Link: https://leetcode.com/problems/permutations-ii/
Level: Medium
*/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    let result = []
    nums.sort((a,b) => a-b)
    let visited = new Array(nums.length).fill(false)
    
    function backtrack(permutations){
        if (permutations.length === nums.length){
            result.push([...permutations])
        } else {
            for (let i = 0; i < nums.length; i++){
                // duplicate check
                if (visited[i] || (i > 0 && nums[i] === nums[i-1] && !visited[i-1])) continue
                visited[i] = true
                permutations.push(nums[i])
                backtrack(permutations)
                visited[i] = false
                permutations.pop()
            }
        }
    }
    
    backtrack([])
    return result
};
