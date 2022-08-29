<?php

// Day 6 : Longest Continuous Increasing Subsequence.

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findLengthOfLCIS($nums) {
        $max = 0;
        $cnt = count($nums)-1;
        $last = 0;
        for ($i=0; $i<$cnt; $i++) {
            if ($nums[$i]>=$nums[$i+1]) {
                if (($i-$last) >= $max) {
                    $max = $i-$last+1;
                }
                $last = $i+1;
            }
        }
        if (($cnt-$last) >= $max) {
            $max = $cnt-$last+1;
        }
        return $max;
    }
}