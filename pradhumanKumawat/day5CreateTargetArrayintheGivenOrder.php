<?php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer[] $index
     * @return Integer[]
     */
    function createTargetArray($nums, $index) {
        $result = [];

        $i = 0;
        foreach ($index as $key => $start) {

            array_splice($result, $start, 0, $nums[$i]);
            $i++;
        }
        return $result;

    }
}