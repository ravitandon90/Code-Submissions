// package main

func merge(nums1 []int, m int, nums2 []int, n int)  {
    size := n+m-1
    i := m-1
    j := n-1

    for i >= 0 && j >= 0 {
        if nums1[i] > nums2[j] {
            nums1[size] = nums1[i]
            i--
        } else {
            nums1[size] = nums2[j]
            j--
        }
        size--
    }
    for i >= 0 {
       nums1[size] = nums1[i]
       i--
       size--
    }
    for j >= 0 {
       nums1[size]=nums2[j];
       j--;
       size--;
    }
}