// package main

func Max(a, b int) int {
    if a < b { return b }
    return a
}

func findLengthOfLCIS(nums []int) int {
    count := 1
    ans := 0
    n := len(nums)
    for i := 1; i < n; i++ {
        if nums[i] <= nums[i-1] { count = 0 }
        count++
        ans = Max(ans, count)
    }
    return Max(ans, count)
}
