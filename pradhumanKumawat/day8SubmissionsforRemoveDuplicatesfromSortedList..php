<?php

//Questions: Day 8 submissions for Remove Duplicates from Sorted List.

/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
    function deleteDuplicates($head) {
        if($head->next==null|| $head==null) return $head;
        $head->next = $this->deleteDuplicates($head->next);
        return $head->val==$head->next->val ? $head->next : $head;
    }

}
