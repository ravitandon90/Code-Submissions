// package main

func numIdenticalPairs(nums []int) int {    
    cache := make([]int, 101)
    n := len(nums)
    for i := 0; i < n; i++ {
        cache[nums[i]]++
    }
    for _, count := range cache {
        cache[0] += (count*(count-1)) >> 1
    }
    return cache[0]
}