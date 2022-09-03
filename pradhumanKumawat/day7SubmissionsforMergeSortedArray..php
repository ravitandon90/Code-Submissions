<?php

// Question : Day 7 submissions for Merge Sorted Array.

class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer $m
     * @param Integer[] $nums2
     * @param Integer $n
     * @return NULL
     */
    function merge(&$nums1, $m, $nums2, $n) {
        $nums1 = array_splice($nums1, 0,$m);
        $nums1 = array_merge($nums1, $nums2);

        sort($nums1);

        return $nums1;
    }
}