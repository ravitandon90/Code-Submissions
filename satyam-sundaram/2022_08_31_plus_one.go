func plusOne(digits []int) []int {
    c, s := 1, 0
    n := len(digits)
    arr := make([]int, n+1)
    for i, _ := range digits {
        s = digits[n-i-1] + c
        arr[i] = s%10
        c = s/10
    }
    if c > 0 {
        arr[n] = c
        n++
    }
    for i:=0;i<n/2;i++ {
        arr[i], arr[n-i-1] = arr[n-i-1], arr[i]
    }
    return arr[:n]
}