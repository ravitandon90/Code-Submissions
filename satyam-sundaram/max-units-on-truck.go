// package main
import (
	"fmt"
	"sort"
 )
 
 func Min(a, b int) int {
	if a < b {
	   return a
	}
	return b
 }
 
 func maximumUnits(boxTypes [][]int, truckSize int) int {
	sort.Slice(boxTypes, func(i, j int) bool {
	   return boxTypes[i][1] >= boxTypes[j][1]
	})
	load := 0
	totalUnits := 0
	for _, box := range boxTypes {
	   load = Min(box[0], truckSize)
	   totalUnits += box[1] * load
	   truckSize -= load
	   if truckSize == 0 {
		  break
	   }
	}
	return totalUnits
 }