func solve(data *[][]int, nums []int, pos, n int) {
    if pos == n-1 {
        d := make([]int, len(nums))
        copy(d, nums)
        *data = append(*data, d)
    }
    for i := pos; i < n; i++ {
        nums[i], nums[pos] = nums[pos], nums[i]
        solve(data, nums, pos+1, n)
        nums[pos], nums[i] = nums[i], nums[pos]
    }
}

func permuteUnique(nums []int) [][]int {
    data2 := make([][]int, 0)
    solve(&data2, nums, 0, len(nums))

    var hash = func(arr []int) string {
        var buffer bytes.Buffer
        for _, v := range arr {
            buffer.WriteString(strconv.Itoa(v))
            buffer.WriteString(".")
        }
        return buffer.String()
    }
    cache := make(map[string]bool, 0)
    // deduplicate
    var data [][]int
    for _, v := range data2 {
        k := hash(v)
        if _, found := cache[k]; found {
            continue
        }
        data = append(data, v)
        cache[k] = true
    }
    return data
}
