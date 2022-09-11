// package main

func intersects(x, y []int) bool {
    var check = func(a, b []int) bool {
        return a[1] <= b[1] && a[1] >= b[0]
    }
    return check(x, y) || check(y, x)
}

func Min(a, b int) int {
    if a < b { return a }
    return b
}

func Max(a, b int) int {
    if a > b { return a }
    return b
}

func save(x, y []int) []int {
    return []int{
        Max(x[0], y[0]),
        Min(x[1], y[1]),
    }
}

func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
    var ans [][]int
    for _, i := range firstList {
        for _, j := range secondList {
            if intersects(i, j) {
                ans = append(ans, save(i, j))
            }
        }
    }
    return ans
}
