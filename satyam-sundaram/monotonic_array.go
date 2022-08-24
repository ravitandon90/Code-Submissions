//package main

func isMonotonic(nums []int) bool {
    n := len(nums)
    if n == 1 { return true }
    increasing := true
    decreasing := true
    for i := 1; i < n; i++ {
        if increasing && nums[i] < nums[i-1] {
            increasing = false
        }
        if decreasing && nums[i] > nums[i-1] {
            decreasing = false
        }
    }
    return increasing || decreasing
}
