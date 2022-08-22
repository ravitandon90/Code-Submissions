// package main

func checkStraightLine(coord [][]int) bool {
    x0 := coord[0][0]
    y0 := coord[0][1]
    // Take the "i"th and the "i+1"th point and compare their slope
    // with the 0th (1st coord) point
    for i := 1; i < len(coord)-1; i++ {
        x1, y1 := coord[i][0], coord[i][1]
        x2, y2 := coord[i+1][0], coord[i+1][1]
        if (y1-y2)*(x0-x2) != (x1-x2)*(y0-y2) {
            return false
        }
    }
    return true
}