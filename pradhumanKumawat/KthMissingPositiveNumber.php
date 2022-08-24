<?php
class Solution
{

    public static function findKthPositivsse($arr, $k)
    {
        $i = 0;
        while ($i < count($arr) && $arr[$i] < $i + $k + 1) $i++;
        return $i + $k;

    }
}
