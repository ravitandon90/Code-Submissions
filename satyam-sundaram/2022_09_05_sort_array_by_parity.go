// package main

func sortArrayByParity(arr []int) []int {
    i, j := 0, 0
    n := len(arr)
    for i < n {
        if arr[i] % 2 == 0 {
            arr[i], arr[j] = arr[j], arr[i]
            j++
        }
        i++
    }
    return arr
}
