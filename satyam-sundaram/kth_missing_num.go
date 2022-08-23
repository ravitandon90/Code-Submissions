// package main
// Author: Satyam Shivam Sundaram

func search(arr []int, k int) int {
    l := 0
    h := len(arr)
    m := 0
    for l < h {
        m = (l+h) >> 1
        if arr[m]-(m+1) >= k {
            h = m
        } else {
            l = m+1
        }
    }
    return l-1
}

func findKthPositive(arr []int, k int) int {
    index := search(arr, k)
    if index < 0 {
        return k
    }
    return k+index+1
}