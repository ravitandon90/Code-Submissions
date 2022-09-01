package main

import "fmt"

func binarySearch(arr []int, low int, high int) int {
	var ans int = -1
	for low <= high {
		mid := low + (high-low)/2
		if arr[mid] == mid {
			ans = mid
			break
		} else if mid < arr[mid] {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return ans
}

func fixedPoint(arr []int, size int) int {
	//Now for searching any element we had to use Binary serach which gives T(n) : O(logn)
	return binarySearch(arr, 0, size-1)
}

func main() {
	//Here array will be given
	var num int
	fmt.Println("Enter the size of the array")
	fmt.Scan(&num)
	//Now taking the array input
	var arr = make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Printf("Enter %dth element: ", i)
		fmt.Scanf("%d", &arr[i])
	}
	//Now took the array now find the index where arr[i] == i property is followed.
	res := fixedPoint(arr, num)
	fmt.Printf("The element is found at index:%d", res)

}
