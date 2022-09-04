<?php

//Questions : Day 11 submissions for Implement strStr().

class Solution {

    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        return preg_match("#$needle#", $haystack, $res, PREG_OFFSET_CAPTURE) ? $res[0][1] : -1;
    }
}