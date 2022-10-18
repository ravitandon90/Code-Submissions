// package main

func Max(a, b int) int {
    if a < b { return b }
    return a
}

func MaxLessThan(def, t int, nums []int) (bool, int) {
    set, m := false, def
    for _, v := range nums {
        if v >= t { continue }
        if !set {
            set, m = true, v
        }
        m = Max(m, v)
    }
    return set, m
}


func thirdMax(nums []int) int {
    m := nums[0]
    for _, v := range nums {
        m = Max(m, v)
    }
    lm := m

    if len(nums) < 3 { return m }
    set, m := MaxLessThan(m, m, nums)
    if !set { return lm }
    
    set, m = MaxLessThan(m, m, nums)
    if !set { return lm }

    return m
}
