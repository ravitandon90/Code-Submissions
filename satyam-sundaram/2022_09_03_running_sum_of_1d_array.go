// package main
func runningSum(nums []int) []int {
    n := len(nums)
    for i := 1; i < n; i++ {
        nums[i] += nums[i-1]
    }
    return nums
}
