<?php

//Question : Day 9 submissions for Maximum Product of Two Elements in an Array.

class Solution
{
    /**
     * @param Integer[] $nums
     *
     * @return Integer
     */
    public function maxProduct(array $nums): int
    {
        $numsCount = count($nums);
        sort($nums);

        return (($nums[$numsCount - 1]) - 1) * ($nums[$numsCount - 2] - 1);
    }
}
