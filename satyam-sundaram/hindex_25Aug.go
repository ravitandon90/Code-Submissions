// package main

func hIndex(citations []int) int {
    sort.Slice(citations, func(i, j int) bool {
        return citations[i] < citations[j]
    })
    n := len(citations)
    for h := 0; h < n; h++ {
        if citations[h] >= n-h {
            return n-h
        }
    }
    return 0
}
