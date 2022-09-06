// package main
func frequencySort(nums []int) []int {
    store := make(map[int]int, 0)
    for _, value := range nums {
        store[value] += 1
    }
    sort.Slice(nums, func(i, j int) bool {
        v1, _ := store[nums[i]]
        v2, _ := store[nums[j]]
        if v1 == v2 { return nums[i] > nums[j] }
        return v1 < v2
    })
    return nums
}
