<?php

//Questions = Day 10 submissions for Sorting the Sentence.

class Solution {

    /**
     * @param String $s
     * @return String
     */
    function sortSentence($s) {
        $s = explode(' ', $s);

        foreach ($s as $w) {
            $result[substr($w, -1)] = substr($w, 0, strlen($w) - 1);
        }

        ksort($result);

        return implode(' ', $result);
    }
}
