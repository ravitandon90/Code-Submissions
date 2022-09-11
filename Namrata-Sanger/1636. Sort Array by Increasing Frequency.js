/*
Day 20
1636. Sort Array by Increasing Frequency
Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
Level: Easy
*/

var frequencySort = function(nums) {
    let maps = new Map()
    
    for (let i = 0; i < nums.length; i++) {
        maps.has(nums[i]) ? maps.set(nums[i],maps.get(nums[i]) + 1) : maps.set(nums[i], 1)
    }
    
    let sorted = [...maps.entries()].sort((a,b) => a[1]===b[1] ? b[0] - a[0] : a[1] - b[1])
    
    let ret = []
    sorted.forEach(x=> {
        while(x[1] > 0) {
            ret.push(x[0])
            x[1]--
        }
    })
    return ret
};
