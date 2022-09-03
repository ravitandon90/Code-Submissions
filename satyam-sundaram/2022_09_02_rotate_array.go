// package main

func reverse(nums []int) {
    n := len(nums)
    for i := 0; i < n/2; i++ {
        nums[i], nums[n-i-1] = nums[n-i-1], nums[i]
    }
}

func rotate(nums []int, k int)  {
    n := len(nums)
    k %= n
    if k == 0 { return }
    reverse(nums[:n])
    reverse(nums[:k])
    reverse(nums[k:])
}
