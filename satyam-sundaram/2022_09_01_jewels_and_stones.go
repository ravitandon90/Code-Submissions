// package main

func numJewelsInStones(jewels string, stones string) int {
    hash := make([]int, 256)
    for _, j := range jewels {
        hash[j] = 1
    }
    count := 0
    for _, stone := range stones {
        count += hash[stone]
    }
    return count
}
