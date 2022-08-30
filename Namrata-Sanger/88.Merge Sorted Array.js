/*
Day 11
88. Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
Level : Easy
*/

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
// time complexity O(n)
var merge = function(nums1, m, nums2, n) {
    m = m-1;
    let p = nums1.length - 1;
    let q = n - 1;
    while(q >= 0){
        if(nums1[m] < nums2[q]  || m == -1){
            nums1[p] = nums2[q];
            q--;
            p--;
        }else if(nums1[m] >= nums2[q]){
            nums1[p] = nums1[m];
            p--;
            m--;
        }
    }
    return nums1;
};
