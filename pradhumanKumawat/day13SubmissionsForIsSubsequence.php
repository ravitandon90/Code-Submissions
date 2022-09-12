<?php

//Questions : Day  13 - Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isSubsequence($s, $t) {

        if(strlen($s) == 0)
            return true;

        for($i = 0; $i < strlen($t); $i++)
        {
            if($t[$i] == $s[0]){
                $s = substr($s, 1);
            }

            if(strlen($s) == 0)
                return true;
        }

        return false;
    }


}