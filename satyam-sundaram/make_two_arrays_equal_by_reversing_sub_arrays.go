// package main


func canBeEqual(target []int, arr []int) bool {
    sort.Ints(target)
    sort.Ints(arr)
    for i := range arr {
        if arr[i] != target[i] {
            return false
        }
    }
    return true
}
